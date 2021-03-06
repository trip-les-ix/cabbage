# Csound Output Widget

Csoundoutput will display Csound output messages within your instrument**s GUI. This widget can be very useful when working in plugin mode and can be invaluable when it comes to de-slugging Cabbage instruments. 


```csharp
csoundoutput bounds(x, y, width, height), text("name"), \
colour("colour"), fontcolour("colour"), identchannel("channel"), \
visible(val), alpha(val), widgetarray("chan", number)
```
<!--(End of syntax)/-->
##Identifiers

### Common Identifiers

{! ./markdown/Widgets/Properties/bounds.md !}  

{! ./markdown/Widgets/Properties/text.md !} 

{! ./markdown/Widgets/Properties/colour.md !} 

{! ./markdown/Widgets/Properties/fontcolour.md !} 

{! ./markdown/Widgets/Properties/identchannel.md !} 

{! ./markdown/Widgets/Properties/alpha.md !} 

{! ./markdown/Widgets/Properties/visible.md !} 

{! ./markdown/Widgets/Properties/widgetarray.md !} 


<!--(End of identifiers)/-->

##Example
```csharp
<Cabbage>
form size(400, 500), caption("Untitled"), pluginID("plu1"), colour(39, 40, 34)
csoundoutput bounds(10, 10, 380, 400)
</Cabbage>
```
![](../images/csoundOutputExample.png)