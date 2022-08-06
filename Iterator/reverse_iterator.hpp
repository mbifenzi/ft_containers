#pragma once 

#include "iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
        protected :
            Iterator _it;
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_type::value_type value_type;
            typedef typename iterator_type::difference_type difference_type;
            typedef typename iterator_type::pointer pointer;
            typedef typename iterator_type::reference reference;
            typedef typename iterator_type::iterator_category iterator_category;

            reverse_iterator() {};
			explicit reverse_iterator(iterator_type it) : _rev_it(--it){};
			reverse_iterator(const reverse_iterator<iterator_type>& rev_it){ this->operator=(rev_it);};
			template<typename Iter>
			reverse_iterator (reverse_iterator<Iter> const& it): _rev_it(--it.base()) {}

			// Access operators
			reference	operator*() const {return *(_rev_it);};
			pointer		operator->() const {return &(*(_rev_it));};
			reference	operator[](difference_type n) const{return _rev_it[-n];};

			// Assignment operations
			reverse_iterator& operator= (const reverse_iterator& rev_it){
				_rev_it = --rev_it.base();
				return (*this);
			};

			reverse_iterator& operator+= (difference_type n){
				_rev_it -= n;
				return (*this);
			};

			reverse_iterator& operator-= (difference_type n){
				_rev_it += n;
				return (*this);
			};

			// Increment / decrement operators
			reverse_iterator& operator++(){
				_rev_it--;
				return (*this);
			}

			reverse_iterator operator++(int){
				reverse_iterator tmp(*this);
				_rev_it--;
				return (tmp);
			}

			reverse_iterator& operator--(){
				_rev_it++;
				return (*this);
			}

			reverse_iterator operator--(int){
				reverse_iterator tmp(*this);
				_rev_it++;
				return (tmp);
			}

			// Arithemtich operators

			reverse_iterator operator+ (difference_type n) const{
				reverse_iterator tmp(*this);
				tmp += n;
				return tmp;
			}

			reverse_iterator operator- (difference_type n) const{
				reverse_iterator tmp(*this);
				tmp -= n;
				return tmp;
			}

			// Const convertion
            operator	reverse_iterator<const iterator_type>() const{
				return reverse_iterator<const iterator_type>(_rev_it);
			}

			iterator_type base() const{
				iterator_type it = _rev_it;
				return (++it);
			};

		protected:
			iterator_type	_rev_it;
    };
template <class Iterator>
  	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		  return lhs.base() == rhs.base();
	};
	template <class Iterator>
  	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		  return lhs.base() != rhs.base();
	};
	template <class Iterator>
  	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		  return lhs.base() <= rhs.base();
	};
	template <class Iterator>
  	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		  return lhs.base() >= rhs.base();
	};
	template <class Iterator>
  	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		  return lhs.base() < rhs.base();
	};
	template <class Iterator>
  	bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
		  return lhs.base() > rhs.base();
	};
	// Arithmetic operators
	template <class Iterator>
  	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, 
	  const reverse_iterator<Iterator>& rev_it){
		  return (rev_it + n);
	};

	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){
		return (rhs.base() - lhs.base());}
}