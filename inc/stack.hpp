#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <vector>

namespace ft{
	template<class T, class Container = std::vector<T> >
	class stack{

		public:
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef Container container_type;

			explicit stack(const Container& = Container());
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push(const value_type& x) { c.push_back(x); }
			void pop() { c.pop_back(); }
			void swap(stack& x) { c.swap(x); }
		protected:
			Container c;
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);
	template <class T, class Container>
	bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);
}

#endif


















// Le conteneur stack est un conteneur adaptateur, ce qui signifie qu'il ne stocke pas directement les éléments
// qu'il contient, mais qu'il utilise un autre conteneur (appelé conteneur sous-jacent) pour stocker ces éléments.

// La classe std::stack<T> définit un membre de données c qui est de type
// std::stack<T>::container_type. Le type std::stack<T>::container_type est
// un alias de type défini par la classe std::stack<T> qui vaut de base deque
// std::stack<class T> est equivalent a std::stack<class T, std::deque<T>>
// donc en gros pour utiliser un autre container, il faut changer la valeur de container_type

// container_type peut valoir 3 containers differents: deque, vector et list
// en realite stack peut utiliser les containers qui peuvent utiliser les fonctions suivantes:
// empty
// size
// back
// push_back
// pop_back

// Le conteneur stack est un conteneur adaptateur de la bibliothèque standard de C++ qui implémente une pile.
// Une pile est une structure de données qui respecte la règle de la pile "dernier entré, premier sorti"
// (LIFO, Last In First Out), ce qui signifie que l'élément qui a été ajouté le dernier est le premier à être retiré.

// std::stack n'est qu'un adaptateur de conteneur, cela signifie qu'il utilise un conteneur sous-jacent pour stocker
// ses données et qu'il fournit une interface d'accès qui ne montre qu'une partie de ces données.