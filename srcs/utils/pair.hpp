// pair.hpp

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <class T1, class T2>
	struct pair {

		typedef	T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		// default constructor
		pair(): first(), second() { }

		// copy constructor
		template<class U, class V>
		pair(const pair<U,V>& pr): first(pr.first), second(pr.second) { }

		// initializes pair with a as first and b as second
		pair(const first_type& a, const second_type& b): first(a), second(b) { }

		// operator overload=
   /*     pair& operator=(const pair& pr) {*/
			//first = pr.first;
			//second = pr.second;
			//return (*this);
		/*}*/

	}; // struct pair

	// operator overload==
	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }

	// operator overload!=
	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs == rhs)); }

	// operator overload<
	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	// operator overload<=
	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(rhs < lhs)); }

	// operator overload>
	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs < lhs); }

	// operator overload>=
	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs < rhs)); }

}; // namespace ft

#endif
