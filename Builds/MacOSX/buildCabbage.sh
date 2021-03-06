#!/bin/bash  
echo "==========================================="
echo "======== Build Script for Cabbage ========="
echo "==========================================="
	
echo "Removing old binaries"
rm -rf ./build/Release/Cabbage.app
rm -rf ./build/Release/CabbagePlugin.vst

/Users/walshr/sourcecode/JUCE/extras/Projucer/Builds/MacOSX/build/Debug/Projucer.app/Contents/MacOS/Projucer --resave ../../CabbageIDE.jucer	

echo "Building Universal build"

xcodebuild -project Cabbage.xcodeproj clean
xcodebuild -project Cabbage.xcodeproj/ ARCHS="i386 x86_64" ONLY_ACTIVE_ARCH=NO -configuration Release

/Users/walshr/sourcecode/JUCE/extras/Projucer/Builds/MacOSX/build/Debug/Projucer.app/Contents/MacOS/Projucer --resave ../../CabbagePlugin.jucer

xcodebuild -project CabbagePlugin.xcodeproj/ ARCHS="i386 x86_64" ONLY_ACTIVE_ARCH=NO -configuration Release GCC_PREPROCESSOR_DEFINITIONS="Cabbage_Plugin_Synth=1 USE_DOUBLE=1 CSOUND6=1 MACOSX=1"
cp -rf ./build/Release/CabbagePlugin.vst/ ./build/Release/Cabbage.app/Contents/CabbagePluginSynth.vst

xcodebuild -project CabbagePlugin.xcodeproj/ -configuration Release ARCHS="i386 x86_64" ONLY_ACTIVE_ARCH=NO GCC_PREPROCESSOR_DEFINITIONS="MACOSX=1 USE_DOUBLE=1"
cp -rf ./build/Release/CabbagePlugin.vst/ ./build/Release/Cabbage.app/Contents/CabbagePluginEffect.vst
rm -rf ./build/Release/CabbagePluginEffect.vst
rm -rf ~/Library/Audio/Plug-Ins/VST/CabbagePlugin.vst
cp -rf ../../Examples ./build/Release/Cabbage.app/Contents/Examples

# cp -rf  /Users/walshr/sourcecode/FMOD\ Programmers\ API/api/lowlevel/examples/xcode32/_builds/Debug/fmod_csound.dylib ./build/Release/Cabbage.app/Contents/fmod_csound.dylib

# echo "Bundling all files"	
# cp -rf ../../Docs/_book ./build/Release/Cabbage.app/Contents/MacOS/Docs
# cp -rf ../../Docs/_book ./build/Release/CabbageStudio.app/Contents/MacOS/Docs


cp ../opcodes.txt ./build/Release/Cabbage.app/Contents/MacOS/opcodes.txt 

/Users/walshr/sourcecode/JUCE/extras/Projucer/Builds/MacOSX/build/Debug/Projucer.app/Contents/MacOS/Projucer --resave ../../CabbageIDE.jucer