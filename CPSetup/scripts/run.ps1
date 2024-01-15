[CmdletBinding()]
[Alias()]
[OutputType([int])]
Param
(
 [Parameter(Mandatory=$true, Position=0)]
 [string]$testCode,
 )

g++ -Wall $testCode -o code
if($? -eq $false){ return "Complied Error : testing code" }

Get-Content .\inp.txt | .\code.exe > .\out.txt
if($? -eq $false){ return "Runtime Error : testing code" }

$Result = diff -ReferenceObject (Get-Content .\exp.txt) -DifferenceObject (Get-Content .\out.txt) -SyncWindow 0
if ($Result.Count -ne 0) {
	Write-Output $Result
		return "Result : Wrong Answer"
}

return "Result : Accepts"

