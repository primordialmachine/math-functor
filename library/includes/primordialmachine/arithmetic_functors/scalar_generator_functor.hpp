#pragma once

#include <type_traits>

namespace primordialmachine {

template<typename SCALAR, typename ENABLED = void>
struct scalar_generator_functor;

template<typename SCALAR>
struct scalar_generator_functor<SCALAR,
                               std::enable_if_t<std::is_floating_point_v<SCALAR>>>
{
  using scalar_type = SCALAR;

  scalar_type m_scalar;

  using result_type = SCALAR;

  scalar_generator_functor()
    : m_scalar()
  {}

  scalar_generator_functor(scalar_type const& scalar)
    : m_scalar(scalar)
  {}

  const result_type& operator()(size_t index) const { return m_scalar; }
  result_type& operator()(size_t index) { return m_scalar; }

}; // struct scalar_generator_functor

} // namespace primordialmachine
