#ifndef N146_LRU_CACHE_H
#define N146_LRU_CACHE_H

#include <bits/stdc++.h>
using namespace std;

namespace n146
{

class LRUCache
{
public:
    LRUCache(int capacity): m_capacity(capacity)
    {

    }

    int get(int key)
    {
        auto it = m_LRUCache.find(key);
        // key not exsit
        if (it == m_LRUCache.end())
        {
            return -1;
        }
        else
        {
            _adjustRecentlyUsedItem(it);
            return it->second.first;
        }
    }

    void put(int key, int value)
    {
        auto it = m_LRUCache.find(key);
        // key not exsit
        if (it == m_LRUCache.end())
        {
            // not full
            if (m_LRUKeyList.size() < m_capacity)
            {
                m_LRUKeyList.push_front(key);
            }
            // full
            else
            {
                _removeLeastRecentlyUsedItem();
                m_LRUKeyList.push_front(key);
            }
        }
        else
        {
            _adjustRecentlyUsedItem(it);
        }
        m_LRUCache[key] = {value, m_LRUKeyList.begin()};
    }
private:
    typedef list<int> KeyList;
    typedef pair<int, KeyList::iterator> Value; // iter of key in the Keylist is part of value
    typedef unordered_map<int, Value> Cache;

    KeyList m_LRUKeyList;
    Cache m_LRUCache;
    int m_capacity;

    void _adjustRecentlyUsedItem(Cache::iterator it)
    {
        m_LRUKeyList.erase(it->second.second);
        m_LRUKeyList.push_front(it->first);
        it->second.second = m_LRUKeyList.begin();
    }

    void _removeLeastRecentlyUsedItem()
    {
        m_LRUCache.erase(m_LRUKeyList.back());
        m_LRUKeyList.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

}

#endif // N146_LRU_CACHE_H
