#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>
# include <vector>


namespace ft{
	template <typename T, class Allocator = std::allocator<T> >
	class vector{
		private:
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;
			pointeur		_first;
		
		public:
			// -- A L I A S E S -----------------------------
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef std::iterator iterator;
			typedef std::iterator const_iterator;
			typedef unsigned long	size_type;
			typedef std::ptrdiff_t difference_type;
			
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer
			typedef std::reverse_iterator<iterator> reverse_iterator;
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


			// Construct/Copy/Destroy:

			explicit vector (const allocator_type& alloc = allocator_type()) _size(0), _capacity(0), _allocator(alloc), _first(NULL){};

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) _size(n), _capacity(n), _allocator(alloc){
				_first = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) _allocator(alloc){
				difference_type	n = std::distance(first, last);
				_capacity = count;
				_size = count;
				//	cas particulier, il faut bien allocate et construct ici parce insert ne peut pas le faire dans ce cas
				this->insert(begin(), first, last);
			}

			vector(const vector<T,Allocator>& x);	// pas d exception

			~vector(){
				if (_capacity == 0)
					return ;
				clear();
				_allocator.deallocate(_first, _capacity);
			}

			vector<T,Allocator>& operator=(const vector<T,Allocator>& x){	// pas d exception
				if (x == *this)
					return *this;
				if (_size != 0)
					clear();
				insert(end(), cpy.begin(), cpy.end());
				return *this;
			}

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const T& u);
			allocator_type get_allocator() const;       //  permet d utiliser le type dallocator qu on utilise dans notre vector donc le deuxieme param de vector

			// Iterators:

			iterator begin(){
				return (iterator(_first));
			}
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			// Capacity:

			size_type size() const{
				return _size;
			}
			size_type max_size() const{
				return _allocator.max_size();
			}
			void resize(size_type sz, T c = T()){   // allocate puis construct
				if (sz < _size)
					this->erase(begin()+sz, end());
				else if (sz > _size)
					//	potentiellement rajouter l allocation auto ici si sz > _capacity mais je vais surement le faire dans insert
					this->insert();
			}

			size_type capacity() const{
				return _capacity;
			}
			bool empty() const{
				return (_size == 0);
			}

			void reserve(size_type n){
				if (n > _capacity)
					_allocator.allocate(n - _capacity) //	on alloue pour avoir _capacity = n (ou plus)
				// cest tout sinon ne fait rien et ne change evidemment pas size
				// attention size_type est un unsigned
			}

			// Element access:

			reference operator[](size_type n){

			}

			const_reference operator[](size_type n) const{

			}

			const_reference at(size_type n) const{

			}

			reference at(size_type n){
				
			}

			reference front(){					// pas d exception si !empty sinon UB

			}

			const_reference front() const{		// pas d exception si !empty sinon UB

			}

			reference back(){					// pas d exception si !empty sinon UB

			}

			const_reference back() const{		// pas d exception si !empty sinon UB

			}

			// Modifiers:

			void push_back(const T& x){		// si renvoie une exception alors ne fait rien parce que UB
				this.insert(end, x);
				// _size++;		se fera dans la fonction insert
			}

			void pop_back(){               // pas d exception
				this.erase(end);
				// _size--;		se fera dans la fonction erase
			}

			iterator insert(iterator position, const T& x);
			// iterator insert (iterator position, const value_type&val)
			// {
			// 	size_t n = position - _first;
			// 	if (_capacity > _size)
			// 	{
			// 		int i = 0;
			// 		while (_size -i > n)
			// 		{
			// 			_alloc.construct(_first + _size - i, *(_first + _size -i-1));			*(_first + _size -i-1) == _first[_size - i - 1] == _size 
			// 			i++;
			// 		}
			// 		_alloc.construct(_first + _size - i , val);
			// 		_size++;


			// 	}
			// 	else
			// 	{
			// 		int i = 0;
			// 		if (_capacity == 0)
			// 			reserve(1);
			// 		else
			// 			reserve(_size *2);
			// 		while (_size -i > n)
			// 		{
			// 			_alloc.construct(_first + _size - i, *(_first + _size -i-1));
			// 			i++;
			// 		}
			// 		if ((_first + _size - i))
			// 			_alloc.destroy(_first + _size - i);
			// 		_alloc.construct(_first + _size - i , val);
			// 		_size++;

			// 	}
			// 	return (_first + n);
			// }

			void insert(iterator position, size_type n, const T& x);
			template <class InputIterator>
			void insert(iterator position,
			InputIterator first, InputIterator last);
			iterator erase(iterator position);                  // pas d exception et deconstruct sans deallocate
			iterator erase(iterator first, iterator last);      // pas d exception et deconstruct sans deallocate
			
			void swap(vector<T,Allocator>& x){
				//	une maniere simple est de calculer x.size() puis de si x.size() > _capacity , on allocate une taille suffisante et on recopie

				//  recopie : vector<T,Allocator>temp = x; x=this; this=temp;

				//	attention il faut bien inverser les 2 donc x devient this et this devient x donc on fait pareil qu au dessus mais pour this aussi
			}

			void clear(){                                   // deconstrcut mais pas deallocate  comme ca on enleve le contenu mais on garde la taille de l allocation d avant pour pas perdre des operations a reallouer apres donc size repasse a 0 mais capacity ne change pas 
				for (size_type i = 0; i < _size; i++){
					_allocator.destroy();
				}
				_size = 0;
			}
			// Non member functions:

			template <class T, class Allocator>
			friend bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);	// pas d exception
			template <class T, class Allocator>
			friend bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);	// pas d exception
			template <class T, class Allocator>
			friend bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);	// pas d exception
			template <class T, class Allocator>
			friend bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);	// pas d exception
			template <class T, class Allocator>
			friend bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);	// pas d exception
			template <class T, class Allocator>
			friend bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);	// pas d exception
			template <class T, class Allocator>
			friend void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);	// pas d exception ou UB
	};
}

#endif

/*
le mot cle friend permet de faire avoir acces (a des fonctions membres) aux variables private


Vector est une sorte de tableau comme en c sauf qu il peut redimentionner dynamiquement sa taille quand il le veut ou le
fait tout seul quand c est necessaire quand on veut ajouter des elements au dela de la taille max. On peut aussi inserer
des elements n importe ou ou en ajouter/supprimer et meme trier les elements.


La cle de voute de Vector sera donc cette redimention permanente des elements c est a dire la variable capacity.
Elle est initialise a 0 puis suit les puissances de 2 en commancant donc par 0 qui vaut donc 1 quand on va ajouter un element.
Puis on ajoute un deuxieme element donc capacity = 2^1=2 puis un troisieme donc capacity = 2^2=4 puis quatrieme capacity mais
capacity etant suffisament grand pour accueullir cet element pas besoin de redimensionner puis un cinquieme donc capaticy = 2^3=8...


En fait capacity va donc dependre de size qui est la variable qui donne le nombre de variable contenu par le conteneur vector.
On a donc : si capacity < size => on change capacity pour que capacity >= size.
Il ne suffit pas de multuplier capacity par 2 parce qu on peut ajouter d un coup pleins d elements.
On divise size par 2 jusqu a obtenir 0 pour connaitre la puissance de 2 de capacity (sauf si size = 0)
ex: size = 10
	10/2 = 5	5/2 = 2		2/2 = 1		1/2 = 0
On doit diviser 10 quatre fois avant d obtenir 0. 2^4=16 donc si size vaut 10, capacity vaut 16.
Cas particulier : le cas de insert.... capacity se multiplie par 2 dans le cas ou on ajoute un seul element par contre si on en 
ajoute pleins d un coup. Dans le cas ou on doit plus que multiplier par 2, capacity prend la valeur de size exacte.





ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok 

En fait dans le cas de insert : soit capacity est suffisant donc on change pas soit capacity pas suffisant donc on change.
Dans ce cas, 2 cas : si size vaut max ((capacity*2) -2) alors capaci











La fonction allocate 
*/

/*
int main()
{
	std::vector<int> myVector;
	std::cout << "Capacité initiale : " << myVector.capacity() << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		myVector.push_back(i);
		std::cout << "Capacité : " << myVector.capacity() << " et la size : " << myVector.size() << std::endl;
	}
	std::vector<int>::iterator it;
	it = myVector.begin();
	myVector.insert(it, {10, 10, 10, 10});
	std::cout << "Capacité : " << myVector.capacity() << " et la size : " << myVector.size() << std::endl;
	return 0;
}

Je ne comprend pas ce bout de code, pourquoi capacity vaut 10 alors que size vaut 9
Enfin je n ai pas a le comprendre mais capacity vaut tjs size + 1 quand size vaut l ancienne capacity + 1 mais c est un cas particulier de merde sa mere!!!
Encore un cas particulier de insert quand size vaut capacity - 1 et qu on ajoute au moins 2 elements ((capacity *= 2) - 2), si on ajoute que 1 bah capacity==size
*/