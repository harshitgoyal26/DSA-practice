#include<unordered_map>
#include<iostream>
#include<cstdlib>
#include <vector>
#include<algorithm>
using namespace std ;


template <typename V>
class MapNode {
    public :
    string key ;
    V val ;
    MapNode *next ;

    MapNode(string key , V val)
    {
        this -> key = key ;
        this -> val = val;
        next = NULL ;
    }

    ~MapNode()
    {
        delete next ;
    }
};


template <typename V>
class OurMap {
    public:
    MapNode<V> ** buckets ;
    int count ;
    int numBuckets ;

    OurMap()
    {
        count = 0 ;
        numBuckets = 5 ;
        buckets = new MapNode<V> *[numBuckets] ;

        for(int i = 0 ; i < numBuckets ; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~OurMap()
    {
        for(int i = 0 ; i < numBuckets ; i++)
        {
            delete buckets[i] ;
        }

        delete [] buckets ;
    }

    int size()
    {
        return count ;
    }

    V getVal(string key)
    {
        int bucketIndex = getBucketIndex(key) ;
        MapNode<V> *head = buckets[bucketIndex] ;

        while(head != NULL)
        {
            if(head -> key == key)
            {
                return head -> val ;
            }
            head = head -> next ;
        }
        return 0 ;
    }

    private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currCoeff = 1 ;

        for(int i = key.length() -1 ; i>=0 ; i--)
        {
            hashCode += key[i] * currCoeff ;
            hashCode = hashCode % numBuckets ;
            
            currCoeff *= 37 ;
            currCoeff = currCoeff % numBuckets ;

        }


        return hashCode % numBuckets ;
    }

    public:
    void insert(string key , V val)
    {
        int bucketIndex = getBucketIndex(key) ;
        MapNode<V> *head = buckets[bucketIndex] ;
        while(head != NULL)
        {
            if(head -> key == key)
            {
                head -> val = val ;
                return ;
            }
            head = head -> next ;
        }

        head = buckets[bucketIndex] ;
        MapNode<V> *newNode = new MapNode<V>(key , val) ;
        newNode -> next = head ;
        buckets[bucketIndex] = newNode ;
        count ++ ;

    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key) ;
        MapNode<V> *head = buckets[bucketIndex] ;
        MapNode<V> *prev = NULL ;

        while(head != NULL)
        {
            if(head -> key == key)
            {
                if(prev == NULL)
                {
                    buckets[bucketIndex] = head -> next ;
                }
                else
                {
                    prev -> next = head -> next ;
                }
                head -> next = NULL ;
                V value = head -> val ;
                delete head ;
                count-- ;
                return value; 
                
            }
            prev = head ;
            head = head -> next ;
        }

        return 0 ;
    }
};



int main()
{
    OurMap<int> m1;
    m1.insert("abc1" , 1) ;
    m1.insert("abc2" , 2) ;
    m1.insert("abc3" , 3) ;
    m1.insert("abc4" , 4) ;
    m1.insert("abc5" , 5) ;


    cout<<m1.size()<<endl;
    cout<<m1.getVal("abc3")<<endl;
    cout<<m1.remove("abc5")<<endl;
    cout<<m1.remove("abc5")<<endl;
    cout<<m1.getVal("abc5")<<endl;

    return 0 ;
}