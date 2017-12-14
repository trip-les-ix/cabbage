# Form

Form creates the main application window. pluginid() is the only required identifier. The default values for size are 600x300. 

<big></pre>
form [caption](#caption)("string"), 
[size](#size)(Width, Height), 
[pluginid](#pluginid)("plug"), 
[guirefresh](#guirefresh)(val), 
[import](#import)("file1", "file2", "etc.."), 
[bundle](#bundle)("./folder1", "file2", "etc.."), 
[colour](#colour)("colour"), 

</pre></big>

<!--(End of syntax)/-->
##Identifiers

### Specific Identifiers
{! ./markdown/Widgets/Properties/caption.md !} 

{! ./markdown/Widgets/Properties/size.md !} 

{! ./markdown/Widgets/Properties/pluginid.md !} 

{! ./markdown/Widgets/Properties/guirefresh.md !}     

{! ./markdown/Widgets/Properties/import.md !}  

{! ./markdown/Widgets/Properties/bundle.md !}  

### Common Identifiers

{! ./markdown/Widgets/Properties/colour.md !}     

<!--(End of identifiers)/-->

##Example
```csharp
<Cabbage>
form size(400, 500), caption("Untitled"), pluginID("plu1"), colour(39, 40, 34)
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

;basic usage
instr 1 
endin

</CsInstruments>
<CsScore>
;causes Csound to run for about 7000 years...
f0 z
;starts instrument 1 and runs it for a week
i1 0 z
</CsScore>
</CsoundSynthesizer>
```

![](../images/formExample.png)