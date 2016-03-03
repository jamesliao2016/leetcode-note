#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>

using namespace std;

/*  为了方便查找，插入，和删除，因此使用双向链表(std::list)和一个哈希表(std::unordered_map) 因为:
 *  1.哈希表保存每个节点的地址，可以保证o(1)时间内查找到节点
 *  2.双向链表插入和删除效率高，单向链表插入和删除时，还要查找节点的前驱节点
 *
 *  越靠近头部，表示节点上次访问距离现在时间最短，尾部节点表示最近访问最少
 *  访问节点的时候，如果节点存在，就把节点交换到链表头，同时更新hash表该节点的地址
 *  插入节点时，如果cache的size达到了上限capacity，就删除尾部节点，同时要在hash表中删除对应的项，新节点插入链表头
 *
 *
 *
 */
class LRUCache{
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k,int v):key(k),value(v){}
    };
public:
    LRUCache(int capacity):m_capacity(capacity) {
    }

    int get(int key) {
        if(m_cacheMap.find(key) == m_cacheMap.end()) return -1;
        m_cachelist.splice(m_cachelist.begin(),m_cachelist,m_cacheMap[key]);
        m_cacheMap[key] = m_cachelist.begin();
    }

    void set(int key, int value) {
        //不存在，就插入
        if(m_cacheMap.find(key) == m_cacheMap.end()) {
            if(m_cachelist.size() == m_capacity) { //容量满了,从链表和map中删除,然后push_fron进去，设置map
                m_cacheMap.erase(m_cachelist.back().key);
                m_cachelist.pop_back();
            }
            m_cachelist.push_front(CacheNode(key,value));
            m_cacheMap[key] = m_cachelist.begin();
        } else {  //存在,就移动到链表头部，然后更新map
            m_cacheMap[key]->value = value;
            m_cachelist.splice(m_cachelist.begin(),m_cachelist,m_cacheMap[key]);
            m_cacheMap[key] = m_cachelist.begin();
        }
    }
private:
    int m_capacity;
    list<CacheNode> m_cachelist;
    unordered_map<int,list<CacheNode>::iterator> m_cacheMap;
};

int main()
{

}
