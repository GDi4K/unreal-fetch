# Unreal Fetch

The [Fetch API](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API/Using_Fetch) inspired HTTP Client for Unreal Engine. Works with both Blueprints & C++.

![](Images/HelloWorldUnrealFetch.png)

**[Watch the Demo](https://www.youtube.com/watch?v=DPVwaP792MA&feature=youtu.be)**

## Features

With this plugin, you can talk to HTTP APIs very quickly from Blueprints. Here are some core features:

* No C++ or configurations needs when using with Blueprints
* Talk to HTTP Apis with a minimal amount of Blueprint nodes
* Allow to parse & make JSON values via Blueprints
* Works anywhere since this uses internal HTTP & JSON related modules.

## Installation

**<sub>This plugin will be available via Unreal Marketplace soon.</sub>**

This plugin is tested with UE 4.26 & 4.25. Since this plugin uses some built-in modules, this will work with all the build targets.

* Close your existing Unreal Engine app.
* Create a directory in your app root called `Plugins`.
* Download [this](https://github.com/GameDev4K/unreal-fetch/archive/main.zip) GitHub repository.
* Copy `Plugins/UnrealFetch` of the repository to above created `Plugins` directory.
* Start your app & it will ask to compile the plugin. Proceed with that.
* You might need to [setup Visual Studio](https://docs.unrealengine.com/en-US/ProductionPipelines/DevelopmentSetup/VisualStudioSetup/index.html) for Unreal Engine.


## Usage with Blueprints

**[Watch this video](https://www.youtube.com/watch?v=DPVwaP792MA&feature=youtu.be)** for step by step instructions on how to use this plugin.

Once installed, you can use the `Fetch` static function inside Blueprints to talk to any HTTP API. Here's [an example](https://blueprintue.com/blueprint/kxwkx692/) on invoking a HTTP POST request & extracting the email from the response JSON.

Refer to the following examples for more usage:<br/>
<sup>(You can copy blueprint nodes from the following examples & directly paste them inside your blueprints.)</sup>

* [Hello World - Making a POST Request](https://blueprintue.com/blueprint/kxwkx692/)
* [Working with JSON](https://blueprintue.com/blueprint/2ayz0vbn/)
* [Check Response Headers](https://blueprintue.com/blueprint/xof4e7_w/)
* [Check Status Code](https://blueprintue.com/blueprint/2p_7qg05/)
* [Handle Errors](https://blueprintue.com/blueprint/tixgg4iv/)
* [Use Custom Headers](https://blueprintue.com/blueprint/4g6x2y-h/)
* [Runtime JSON Validation](https://blueprintue.com/blueprint/foc1vk8h/)
* [Working with Arrays](https://blueprintue.com/blueprint/k4fbbdse/)

## Functional Test Suite

All the tests for this plugin written as Functional Tests & they are based on Blueprints. That's a good place to search for each & every functionality of this plugin.

Here's how to access & run them:

* Clone this repository & run the app [UnrealFetchDevApp](./UnrealFetchDevApp)
* Check `Content/Tests` from the content browser for various blueprints with test cases.
* Open the test runner with `Windows -> Test Automation`.
* Open the Automation tab & search for `Functional Tests`.
* Select all those tests & run them all.
