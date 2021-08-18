// Stack.hpp

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack {

	public:

		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	protected:

		container_type	_container;

	public:

	// --- MEMBER FUNCTIONS ---

		explicit stack(const container_type& ctnr = container_type()): _container(ctnr) { }

		bool empty() const { return (_container.empty()); }

		size_type size() const { return (_container.size()); }

		value_type& top() { return (_container.back()); }

		const value_type& top() const { return (_container.back()); }

		void push(const value_type& val) { _container.push_back(val); }

		void pop() { _container.pop_back(); }

		friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._container == rhs._container); }

		friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._container < rhs._container); }

	}; // class stack

	// --- NON MEMBER FUNCTION OVERLOADS ---

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (!(lhs == rhs)); }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (!(rhs < lhs)); }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (rhs < lhs); }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (!(lhs < rhs)); }

}; // namespace ft

#endif
