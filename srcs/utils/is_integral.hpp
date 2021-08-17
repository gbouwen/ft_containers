// is_integral.hpp

#ifndef IS_INTEGRAL_HPP
# define IS_INTERGRAL_HPP

namespace ft {

	template <class T>
	struct integral_base {
		static const bool value = false;
	}; // is_integral_base

	template<> struct is_integral_base<bool> { static const bool value = true; };
	template<> struct is_integral_base<char> { static const bool value = true; };
	template<> struct is_integral_base<char16_t> { static const bool value = true; };
	template<> struct is_integral_base<char32_t> { static const bool value = true; };
	template<> struct is_integral_base<wchar_t> { static const bool value = true; };
	template<> struct is_integral_base<signed char> { static const bool value = true; };
	template<> struct is_integral_base<short int> { static const bool value = true; };
	template<> struct is_integral_base<int> { static const bool value = true; };
	template<> struct is_integral_base<long int> { static const bool value = true; };
	template<> struct is_integral_base<long long int> { static const bool value = true; };
	template<> struct is_integral_base<unsigned char> { static const bool value = true; };
	template<> struct is_integral_base<unsigned short int> { static const bool value = true; };
	template<> struct is_integral_base<unsigned int> { static const bool value = true; };
	template<> struct is_integral_base<unsigned long int> { static const bool value = true; };
	template<> struct is_integral_base<unsigned long long int> { static const bool value = true; };

	template <class T>
	struct is_integral : integral_base<T> {
		static const bool value = is_integral<T>::value;

		operator bool() const {
			return (value);
		};
	}; // is_integral
}; //namespace ft

#endif
