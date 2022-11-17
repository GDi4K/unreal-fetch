rmdir /S /Q ToPackage

md ToPackage
md ToPackage\Fetch_46

xcopy UnrealFetchDevApp\Plugins\Fetch\Fetch.uplugin ToPackage\Fetch_46

md ToPackage\Fetch_46\Config
xcopy UnrealFetchDevApp\Plugins\Fetch\Config ToPackage\Fetch_46\Config /E/H

md ToPackage\Fetch_46\Resources
xcopy UnrealFetchDevApp\Plugins\Fetch\Resources ToPackage\Fetch_46\Resources /E/H

md ToPackage\Fetch_46\Source
xcopy UnrealFetchDevApp\Plugins\Fetch\Source ToPackage\Fetch_46\Source /E/H

md ToPackage\Fetch_46\Content
xcopy UnrealFetchDevApp\Plugins\Fetch\Content ToPackage\Fetch_46\Content /E/H

echo "Copying the 4.7 version"
md ToPackage\Fetch_47
xcopy ToPackage\Fetch_46 ToPackage\Fetch_47 /E/H

cscript //NoLogo sed.vbs s/(4.26.0)/4.27.0/ < ToPackage\Fetch_46\Fetch.uplugin > ToPackage\Fetch_47\Fetch.uplugin

echo "Copying the 5.0 version"
md ToPackage\Fetch_50
xcopy ToPackage\Fetch_46 ToPackage\Fetch_50 /E/H

cscript //NoLogo sed.vbs s/(4.26.0)/5.0.0/ < ToPackage\Fetch_46\Fetch.uplugin > ToPackage\Fetch_50\Fetch.uplugin

echo "Copying the 5.1 version"
md ToPackage\Fetch_51
xcopy ToPackage\Fetch_46 ToPackage\Fetch_51 /E/H

cscript //NoLogo sed.vbs s/(4.26.0)/5.1.0/ < ToPackage\Fetch_46\Fetch.uplugin > ToPackage\Fetch_51\Fetch.uplugin

@REM Identifying the version
FOR /F "tokens=*" %%g IN ('git describe --tags') do (SET VERSION=%%g)

@REM Making zip files
cd ToPackage
tar.exe -a -c -f Fetch_51_%VERSION%.zip Fetch_51
tar.exe -a -c -f Fetch_50_%VERSION%.zip Fetch_50
tar.exe -a -c -f Fetch_47_%VERSION%.zip Fetch_47
tar.exe -a -c -f Fetch_46_%VERSION%.zip Fetch_46