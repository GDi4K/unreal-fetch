# Unreal Fetch

The [Fetch API](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API/Using_Fetch) inspired HTTP Client for Unreal Engine. Works with both Blueprints & C++.

![](Images/HelloWorldUnrealFetch.png)

## Installation

**<sub>This plugin will be available via Unreal Marketplace soon.</sub>**

This plugin is tested with UE 4.26 & 4.25. Since this plugin uses some built-in modules, this will work with all the build targets.

* Close your existing Unreal Engine app.
* Create a directory in your app root called `Plugins`
* Download a release from [here]()
* Extract it into the above created `Plugins` directory
* Start your app & it will ask to compile the plugin. Proceed with that.
* You might need to [setup Visual Studio](https://docs.unrealengine.com/en-US/ProductionPipelines/DevelopmentSetup/VisualStudioSetup/index.html) for Unreal Engine.


## Usage with Blueprints

This plugin exposes a set of static functions & classes to work with both HTTP & manage JSON. You can use them inside Blueprints & there's no need to use C++.


## Functional Test Suite

All the tests for this plugin written as Functional Tests & they are based on Blueprints. That's a good place to search for each & every functionality of this plugin.

Here's how to access & run them:

* Clone this repository & run the app [UnrealFetchDevApp](./UnrealFetchDevApp)
* Check `Content/Tests` from the content browser for various blueprints with test cases.
* Open the test runner with `Windows -> Test Automation`.
* Open the Automation tab & search for `Functional Tests`.
* Select all those tests & run them all.