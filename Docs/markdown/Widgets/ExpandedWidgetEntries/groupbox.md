# Group Box

Groupbox creates a container for other GUI widgets. They do not communicate with Csound but can be useful for organising widgets into panels.

<big></pre>
groupbox [linethickess](#linethickess)(value), 
[outlinethickness](#outlinethickness)(value), 
[text](#text_groupbox)("caption"), 
[popup](#popup)(val), 
[alpha](#alpha)(val), 
[active](#active)(val), 
[bounds](#bounds)(x, y, width, height), 
[colour](#colour)("colour"), 
[fontcolour](#fontcolour)("colour"), 
[identchannel](#identchannel)("channel"), 
[rotate](#rotate)(radians, pivotx, pivoty), 
[svgfile](#svgfile)("type", "file"), 
[visible](#visible)(val), 
[widgetarray](#widgetarray)("chan", number), 

</pre></big>

<!--(End of syntax)/-->

##Identifiers

### Specific Identifiers

{! ./markdown/Widgets/Properties/linethickess.md !}

{! ./markdown/Widgets/Properties/outlinethickness.md !}  

{! ./markdown/Widgets/Properties/text_groupbox.md !}

{! ./markdown/Widgets/Properties/popup.md !} 

**plant("name")** [DEPRECATED] Sets the name of the plant. No two plants can have the same name. See [Plants](./plants.md)

**popup(val)** [DEPRECATED] If the groupbox is a plant, a value of 1 will cause the groupbox to open in a new window when show(1) is called. popup() should always be used in conjunction with the show() identifier. See [Plants](./plants.md)

**show(val)** [DEPRECATED] A value of 1 will cause the popup plant to show. A value of 0 will close the popup plant. See [Plants](./plants.md)

### Common Identifiers

{! ./markdown/Widgets/Properties/alpha.md !}  

{! ./markdown/Widgets/Properties/active.md !}  

{! ./markdown/Widgets/Properties/bounds.md !}  

{! ./markdown/Widgets/Properties/colour.md !}  

{! ./markdown/Widgets/Properties/fontcolour.md !}   

{! ./markdown/Widgets/Properties/identchannel.md !}  

{! ./markdown/Widgets/Properties/rotate.md !}  

{! ./markdown/Widgets/Properties/svgfile.md !}  

{! ./markdown/Widgets/Properties/visible.md !}  

{! ./markdown/Widgets/Properties/widgetarray.md !}  

<!--(End of identifiers)/-->

##Example
```csharp
<Cabbage>
form caption("Groupbox example") size(400, 300), colour(220, 220, 220), pluginID("def1")
label bounds(8, 6, 368, 20), text("Basic Usage"), fontcolour("black")
groupbox bounds(10, 34, 378, 73), text("I'm a groupbox"), colour(80, 80, 80)
groupbox bounds(8, 118, 380, 177), text("Randomly Updated Identifiers")
groupbox bounds(142, 140, 146, 145), identchannel("widgetIdent"), text("Groupbox")
</Cabbage>
<CsoundSynthesizer>
<CsOptions>
-n -d -+rtmidi=NULL -M0 -m0d 
</CsOptions>
<CsInstruments>
; Initialize the global variables. 
sr = 44100
ksmps = 32
nchnls = 2
0dbfs = 1

seed 0 
;basic usage
instr 1

endin

</CsInstruments>
<CsScore>
;causes Csound to run for about 7000 years...
f0 z
;starts instrument 1 and runs it for a week
i1 0 z
i2 0 z
</CsScore>
</CsoundSynthesizer>
```

![](../images/groupBoxExample.png)