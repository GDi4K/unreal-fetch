rmdir /S /Q ToPackage

md ToPackage
md ToPackage\Fetch

xcopy UnrealFetchDevApp\Plugins\Fetch\Fetch.uplugin ToPackage\Fetch

md ToPackage\Fetch\Config
xcopy UnrealFetchDevApp\Plugins\Fetch\Config ToPackage\Fetch\Config /E/H

md ToPackage\Fetch\Resources
xcopy UnrealFetchDevApp\Plugins\Fetch\Resources ToPackage\Fetch\Resources /E/H

md ToPackage\Fetch\Source
xcopy UnrealFetchDevApp\Plugins\Fetch\Source ToPackage\Fetch\Source /E/H