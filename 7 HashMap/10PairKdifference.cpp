#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V val;
    MapNode *next;

    MapNode(string key, V val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class OurMap
{
public:
    MapNode<V> **buckets;
    int count;
    int numBuckets;

    OurMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];

        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~OurMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }

        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getVal(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->val;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currCoeff = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currCoeff;
            hashCode = hashCode % numBuckets;

            currCoeff *= 37;
            currCoeff = currCoeff % numBuckets;
        }

        return hashCode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                insert(head->key, head->val);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
        {
            delete temp[i];
        }

        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }

    void insert(string key, V val)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->val = val;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V> *newNode = new MapNode<V>(key, val);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;

        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                head->next = NULL;
                V value = head->val;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }

        return 0;
    }
};

string extractUnique(string input)
{
    string c = "";
    unordered_map<char, int> m1;

    for (int i = 0; i < input.length(); i++)
    {
        int check = m1.count(input[i]);
        if (check == 0)
        {
            c += input[i];
        }
        m1[input[i]]++;
    }

    return c;
}

void longestSeq(int *arr, int n)
{
    unordered_map<int, bool> m1;
    for (int i = 0; i < n; i++)
    {
        m1[arr[i]] = true;
    }

    int maxlen = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        if (m1[arr[i]] == true)
        {
            int m = arr[i] + 1;
            int len = 1;
            while (m1[m] == true)
            {
                len++;
                m1[m] = false;
                m++ ;
            }

            m = arr[i] - 1;
            while (m1[m] == true)
            {
                len++;
                m1[m] = false;
                m-- ;
            }
            if(len > maxlen)
            {
                maxlen = len ;
                start = m +1 ;
            }
        }
    }

    cout<<start<<" "<<start + maxlen -1<<endl;
}


int pairK(int *arr , int n , int k)
{
    unordered_map<int , int> m1 ;

    for(int i = 0 ; i < n ; i++)
    {
        m1[arr[i]]++ ;
    }
    int res = 0;
    unordered_map<int,int>::iterator it = m1.begin() ;

    while(it != m1.end())
    {
        if(m1.count(it -> first +k) > 0)
        {
            res += m1[it -> first] * m1[it -> first + k];
        }
        it++ ;
    }

    return res ;
}

int main()
{
    // OurMap<int> m1;
    // m1.insert("abc1" , 1) ;
    // m1.insert("abc2" , 2) ;
    // m1.insert("abc3" , 3) ;
    // m1.insert("abc4" , 4) ;
    // m1.insert("abc5" , 5) ;

    // cout<<m1.size()<<endl;
    // cout<<m1.getVal("abc3")<<endl;
    // cout<<m1.remove("abc5")<<endl;
    // cout<<m1.remove("abc5")<<endl;
    // cout<<m1.getVal("abc5")<<endl;

    // OurMap<int> m2;

    // for(int i = 0; i < 10 ; i++)
    // {
    //     string  key = "abc" ;
    //     char c ='0' + i ;

    //     key = key + c ;
    //     int value = 1 + i ;
    //     m2.insert(key , value) ;
    //     cout<<m2.getLoadFactor()<<endl ;
    // }

    // cout<<m2.size() <<endl ;
    // m2.remove("abc3") ;
    // m2.remove("abc7") ;
    // cout<<m2.size()<<endl ;

    // for(int i = 0 ; i < 10 ; i++)
    // {
    //     string  key = "abc" ;
    //     char c ='0' + i ;

    //     key = key + c ;
    //     cout<<key<<" : "<<m2.getVal(key)<<endl ;
    // }

    // cout<<m2.size() <<endl ;

    // cout << extractUnique("ababcde") << endl;

    // int arr[] = { 2 ,12, 9 ,16, 10, 5, 3, 20, 25, 11, 1, 8, 6};
    // int arr1[] = {3, 7, 2, 1, 9, 8, 41};
    // longestSeq(arr1 , 7) ;

    int arr[] = {5,2,1,4} ;
    cout<<pairK(arr , 4, 3)<<endl; 


    return 0;
}