
# Advanced source engine 2013

Valve official source engine 2013 release code does not include some features like gameui, launcher, etc...

So, using the 2017 Source Engine source code leaks, I tried to link some missing items source code that Valve didn't release.

## Features
- appframework (library)
- launcher (launcher.dll)
- launcher_main (hl2.exe)
## Current tasks
Port the other missing items like:
- GameUI
- Hammer_dll
- Hammer_launcher
- engine.dll source code
- bsp v19-v21 support
- mdl v46-49 support
- VTF 7.5 support
- Achivement system sould work without steam
- Rewrite serverbrowser to work without steam
## Requirements
- [source engine 2013 source code sdk](https://github.com/ValveSoftware/source-sdk-2013)
## Installation

past everything here into your source code directory (ex: source-2013/sp/src/...)

then after that move to 'vpc_scripts/projects.vgc' and just past the next code above ( $Project "captioncompiler" )

```
$Project "appframework"
{
	"appframework\appframework.vpc" [$WIN32]
}

$Project "launcher"
{
	"launcher\launcher.vpc" [$WIN32]
}

$Project "launcher_main"
{
	"launcher_main\launcher_main.vpc" [$WIN32]
}
```

then after that move to 'vpc_scripts/groups.vgc' and just past the next code above ( $Group "gamedlls" )

```
$Group "application"
{
	"appframework"
	"launcher"
	"launcher_main"
}
```

then just inside :

```
$Group "everything"
{
	...
}
```

paste :

```
	"appframework"
	"launcher"
	"launcher_main"
```
	
to be like this : 

```
$Group "everything"
{
	"appframework"
	"launcher"
	"launcher_main"
	
	...
}