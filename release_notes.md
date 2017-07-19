# Release Notes

New release fixing several bugs that slipped into the R1323 release. XNA 4.0 assemblies only, all Windows builds are compiled targeting the .NET 4.0 Client Profile.

Requires either Visual C# 2010 Express or Visual Studio 2010, both with XNA Game Studio 4.0.
3rd party libraries needed to compile and run the source code are included, so everything will compile out of the box.

Changes:
- All assemblies upgraded to NMock3 (enables signing, improves refactoring-friendliness)
- All release assemblies now have been signed with a strong name
- Nuclex.Input was listing certain types of controllers twice, once for the XInput API and once for DirectInput
- The assemblies that had disappeared in the previous release (audio, networking, etc. ) are back
- Windows Keyboard class had reported key states inverted - fixed
- The Y axes of DirectInput controllers were upside-down - fixed
- Axis assignments beyond the standard axes for DirectInput game pads were messed up - fixed
- Removed nunit.framework.dll dependency from TrueTypeImporter (but not framework assemblies)
- Release ships as .zip instead of .7z
