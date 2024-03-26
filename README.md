# MorseCodeConverter

[![Build](https://github.com/xorz57/MorseCodeConverter/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/MorseCodeConverter/actions/workflows/Build.yml)

![image](https://github.com/xorz57/MorseCodeConverter/assets/84932056/d40867e3-bcd7-4ec8-9aa9-b8e104ad6afb)

## Features

- Translate Text to Morse Code.
- Translate Morse Code to Text.
- Load Text or Morse Code from a file.
- Save Text or Morse Code to a file.

## Dependencies

- [Qt Base](https://github.com/qt/qtbase)

## How to Build

#### Linux & macOS

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

git clone https://github.com/xorz57/MorseCodeConverter.git
cd MorseCodeConverter
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

#### Windows

```powershell
git clone https://github.com/microsoft/vcpkg.git C:/vcpkg
C:/vcpkg/bootstrap-vcpkg.bat
C:/vcpkg/vcpkg.exe integrate install

git clone https://github.com/xorz57/MorseCodeConverter.git
cd MorseCodeConverter
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

We would like to express our gratitude to the authors and maintainers of the libraries and tools that MorseCodeConverter depends on. Their work is greatly appreciated.

## Contact

For questions, suggestions, or feedback, feel free to contact us:

- Email: [xorz57@gmail.com](mailto:xorz57@gmail.com)
- GitHub: [xorz57](https://github.com/xorz57)
