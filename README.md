# **2D-Platform-Game**
## Instruckja

&nbsp;
* Pobieramy i wypakowujemy projekt w wybrane miejsce,
* Uruchamiamy za pomocą Visual Studio plik Projekt.sln,
* Z okna Solution Explorera wybieramy Projekt a następnie właściwości,
* Ustawiamy konfigurację na "All Configurations"
* Otwieramy zakładkę C/C++ a następnie wklejamy w opcji "Additional Include Directories" pełną ścieżkę aż folderu "SFML-2.5.1\include".
  Przykładowa ścieżka:
  ```git
  C:\Users\fiZZy\Desktop\2D-Platform-Game\SFML-2.5.1\include
  ```
* Rozwijamy zakładkę Linker a następnie otwieramy General gdzie w opcji "Additional Library Directories" wklejamy pełną ścieżkę aż do folderu SFML-2.5.1\lib.
  Przykładowa ścieżka:
  ```git
  C:\Users\fiZZy\Desktop\2D-Platform-Game\SFML-2.5.1\lib
  ```
* Wchodzimy w zakładkę Linker a następnie otwieramy Input gdzie w opcji "Additional Dependencies" wklejamy poniższe zależności przed znajdującymi się tam już rzeczami:
```git
sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-network-d.lib;sfml-audio-d.lib;
```
