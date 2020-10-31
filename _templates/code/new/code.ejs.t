---
to: source/<%= name %>.cpp
unless_exists: true
---
#include <opensteno/<%= name %>.hpp>

namespace opensteno {
  <%= name %>::<%= name %>(){
  }
} /* namespace opensteno */
