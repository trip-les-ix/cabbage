# Button

Button creates a button on screen that can be used for a whole range of different tasks. The "channel" string identifies the channel on which Cabbage will communicate with Csound. "OnCaption" and "OffCaption" determine the strings that will appear on the button as users toggle between two states, i.e., 0 or 1. By default these captions are set to "On" and "Off" but the user can specify any strings they wish. 

```csharp
button bounds(x, y, width, height), channel("chan"), text("offCaption","onCaption"), \
value(val), colour:N("colour"), fontcolour:N("colour"), latched(val), \
identchannel("channel"), alpha(val), visible(val), caption("caption"), \ 
rotate(radians, pivotx, pivoty), widgetarray("chan", number), popuptext("text") \
active(val), svgfile("type", "file")
```
<!--(End of syntax)/-->

##Identifiers

### Specific Identifiers

{! ./markdown/Widgets/Properties/latched.md !} 

### Common Identifiers
{! ./markdown/Widgets/Properties/active.md !}

{! ./markdown/Widgets/Properties/alpha.md !} 

{! ./markdown/Widgets/Properties/bounds.md !} 

{! ./markdown/Widgets/Properties/caption.md !} 

{! ./markdown/Widgets/Properties/channel.md !} 

{! ./markdown/Widgets/Properties/colour_0.md !} 

{! ./markdown/Widgets/Properties/colour_1.md !} 

{! ./markdown/Widgets/Properties/fontcolour_0.md !} 

{! ./markdown/Widgets/Properties/fontcolour_1.md !} 

{! ./markdown/Widgets/Properties/identchannel.md !} 

{! ./markdown/Widgets/Properties/popup.md !} 

{! ./markdown/Widgets/Properties/rotate.md !} 

{! ./markdown/Widgets/Properties/svgfile.md !} 

{! ./markdown/Widgets/Properties/text.md !} 

{! ./markdown/Widgets/Properties/value.md !} 

{! ./markdown/Widgets/Properties/visible.md !} 

{! ./markdown/Widgets/Properties/widgetarray.md !} 

<!--(End of identifiers)/-->

>colour:1() and fontcolour:1() can be set using colour() and fontcolour(). However, it's recommended that you use the numerated colour identifiers in order to make your code as readable a possible. 

##Example
```csharp
<Cabbage>
form size(400, 500), caption("Untitled"), pluginID("plu1"), colour(39, 40, 34)
button bounds(20, 16, 100, 30), channel("button"),  text("Push me"), fontcolour("white")
infobutton bounds(120, 16, 100, 30), channel("button"),  file("README.txt"), text("Info")
filebutton bounds(220, 16, 100, 30), channel("button"),  populate("*.wav", ""), text("Browse")
</Cabbage>
```

![Button](../images/buttonExample.png)