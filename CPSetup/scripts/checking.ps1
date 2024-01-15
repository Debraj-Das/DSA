[CmdletBinding()]
[Alias()]
[OutputType([int])]
Param
(
 [Parameter(Mandatory=$true,Position=0)]
 [string]$TestCode,

 [Parameter()]
 [string]$CheckCode=".\brute.cpp",

 [Parameter()]
 [string]$Generator=".\inputGen.cpp",

 [Parameter()]
 [int]$loop=100
 )

g++ -Wall $CheckCode -o check
if($? -eq $false){ return "Complied Error : Checking code" }
else { echo "$CheckCode Complied Success" }

g++ -Wall $Generator -o gen
if($? -eq $false){ return "Complied Error : Generator code" }
else { echo "$Generator Complied Success" }


g++ -Wall $TestCode -o code
if($? -eq $false){ return "Complied Error : testing code" }
else { echo "$TestCode Complied Success" }


for([int]$i = 0;$i -lt $loop; $i++)
{
	echo "TC $($i+1) : "

		.\gen.exe > inp.txt
		if($? -eq $false){ return "Runtime Error : Generator code" }

	Get-Content .\inp.txt | .\code.exe > .\out.txt
		if($? -eq $false){ return "Runtime Error : testing code" }

	Get-Content .\out.txt | .\check.exe
		if($? -eq $false){ return "Result : Wrong Anwser" }

}

rm .\check.exe 
rm .\code.exe 
rm .\gen.exe 

return "Result : Accepts"
