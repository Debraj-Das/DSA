[CmdletBinding()]
[Alias()]
[OutputType([int])]
Param
(
 [Parameter(Mandatory=$true,
	 Position=0)]
 [string]$testCode,

 [Parameter()]
 [string]$ExpectCode=".\brute.cpp",

 [Parameter()]
 [string]$Generator=".\inputGen.cpp",

 [Parameter()]
 [int]$loop=1000
 )

g++ -Wall $testCode -o code
if($? -eq $false){ return "Complied Error : testing code" }

g++ -Wall $ExpectCode -o exp
if($? -eq $false){ return "Complied Error : Expected code" }

g++ -Wall $Generator -o gen
if($? -eq $false){ return "Complied Error : Generator code" }


for([int]$i = 0;$i -lt $loop; $i++)
{
	echo "TC $($i+1) : "

		.\gen.exe > inp.txt
		if($? -eq $false){ return "Runtime Error : Generator code" }

	Get-Content .\inp.txt | .\exp.exe > .\exp.txt
		if($? -eq $false){ return "Runtime Error : Expected code" }

	Get-Content .\inp.txt | .\code.exe > .\out.txt
		if($? -eq $false){ return "Runtime Error : testing code" }

	$Result = diff -ReferenceObject (Get-Content .\exp.txt) -DifferenceObject (Get-Content .\out.txt) -SyncWindow 0
		if ($Result.Count -ne 0) {
			Write-Output $Result
				return "Result : Wrong Answer"
		}
}

rm .\exp.exe
rm .\code.exe
rm .\gen.exe

return "Result : Accepts"

