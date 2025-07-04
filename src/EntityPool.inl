#ifndef ENTITY_POOL_INL
#define ENTITY_POOL_INL

#include "EntityPool.h"

// Constructor

template <class T, std::size_t N>
EntityPool<T,N>::EntityPool() : activeCount_(0){
    freeIndices_.reserve(N);
    for (std:size_t i=0; i < N; ++i) freeIndices_.push_back(i);
}

// Destructor
template <class T, std::size_t N>
EntityPool<T,N>::~EntityPool() {
    for(auto ptr : activeEntities()) ptr->~T();
}


template <class T, std::size_t N>
T* EntityPool<T,N>::acquire() {
    
}



#endif // ENTITY_POOL_INL
