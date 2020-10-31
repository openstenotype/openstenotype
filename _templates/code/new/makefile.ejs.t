---
inject: true
to: source/CMakeLists.txt
after: Main.cpp
skip_if:  <%= name %>.cpp
---
  <%= name %>.cpp