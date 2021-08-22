// Map.hpp

#ifndef MAP_HPP
# define MAP_HPP

# include <cstddef>
# include <memory>

# include "utils/pair.hpp"
# include "utils/make_pair.hpp"
# include "utils/less_binary_function.hpp"
# include "utils/node.hpp"

namespace ft {

	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map {

		public:

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		typedef Alloc									allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		// bidirectional_iterator
		// const bidirectional_iterator
		// reverse_iterator
		// const_reverse_iterator
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;
		typedef ft::node<T>*							node_pointer;

		class value_compare: ft::binary_function<value_type, value_type, bool> {

			friend class map;

			protected:

				Compare	comp;
				value_compare(Compare c) : comp(c) {}

			public:

				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;

				bool operator() (const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
				}

		}; // class value_compare

		private:

			size_type		_size;
			node_pointer	_root;
			Compare			_comp;
			allocator_type	_allocator;

		public:

		// --- CONSTRUCTOR/DESTRUCTOR/OPERATOR= ---
			explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()): _size(0), _root(), _comp(comp), _allocator(alloc) { }

		// --- ITERATORS ---

		// --- CAPACITY ---

			// returns true if empty
			bool empty() const { return (!_size); }

			// returns container size
			size_type size() const { return (_size); }

			// size_type max_size() const;

		// --- ELEMENT ACCESS ---

		// --- MODIFIERS ---

		// --- OBSERVERS ---

			// returns key_compare object
			key_compare key_comp() const { return (_comp); }

			// returns value_compare object
			value_compare value_comp() const { return (value_compare(_comp)); }

		// --- OPERATIONS ---

		// --- ALLOCATOR ---

			// returns allocator
			allocator_type get_allocator() const { return (_allocator); }

	}; // class map

}; // namespace ft

#endif
