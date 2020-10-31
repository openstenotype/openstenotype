---
to: include/opensteno/<%= name %>.hpp
unless_exists: true
---

#ifndef OPENSTENO_<%= h.changeCase.constant(name) %>_HPP
#define OPENSTENO_<%= h.changeCase.constant(name) %>_HPP

namespace opensteno {
  class <%= name %> {
  public:
    <%= name %>();
  };
} /* namespace opensteno */
#endif //OPENSTENO_<%= h.changeCase.constant(name) %>_HPP
