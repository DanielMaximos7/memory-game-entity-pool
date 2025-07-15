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
    for(std::size_t i = 0; i < N; ++i){
        //if slot is not free (i is not found in freeIndices_, destroy the object
        if(std::find(freeIndices_.begin(), freeIndices_.end(), i) == freeIndices_.end(){
            T* obj = reinterpret_cast<T*>(buffer_ + i * sizeof(T));
            obj->~T(); // Call destructor
        }
    }
}


template <class T, std::size_t N>
T* EntityPool<T,N>::acquire() {
    if(freeIndices_.empty()) return nullptr;
    std::size_t idx = freeIndices_.back(); freeIndices_.pop_back();
    T* obj = reinterpret_cast<T*>(buffer_ +idx * sizeof(T));
    new (obj) T(); // Call constructor
    ++activeCount_;
    return obj;
}





#endif // ENTITY_POOL_INL
