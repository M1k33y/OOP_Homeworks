#include <iostream>
#include <cstring>

using namespace std;
template <typename K, typename V>

class Map
{
private:
	struct Elem
	{
		K key;
		V value;
		int index;
	};

	Elem elem[100];
	int nr = 0;

public:

	void Set(const K& key, V& value)
	{
		int ok = 0;
		for (int i = 0; i < nr && ok == 0; i++)
			if (elem[i].key == key)
			{
				elem[i].value = value;
				ok = 1;
			}
		elem[nr] = { key,value,nr };
		nr++;
	}

	bool Get(const K& key, V& value)
	{
		for (int i = 0; i < nr; i++)
			if (elem[i].key == key)
			{
				value = elem[i].value;
				return true;
			}
		return false;
	}

	int Count()
	{
		return nr;
	}

	void Clear()
	{

		nr = 0;
	}

	bool Delete(const K& key)
	{
		for (int i = 0; i < nr; i++)
			if (elem[i].key == key)
			{
				for (int j = i + 1; j < nr; j++)
					elem[j - 1] = elem[j];
				nr--;
				return true;
			}
		return false;
	}
	bool Includes(const Map<K, V>& map)
	{
		if (nr < map.nr)
			return false;
		for (int i = 0; i < map.nr; i++)
			for (int j = 0; j < nr; j++)
				if (map.elem[i].key != elem[j].key)
					return false;
		return true;
	}


	V& operator[](const K& key)
	{
		for (int i = 0; i < nr; i++)
			if (elem[i].key == key)
				return elem[i].value;

		elem[nr] = { key, V(), nr };
		nr++;
		return elem[nr-1].value;
	}

	const Elem* begin() const {
		return &elem[0];
	}
	const Elem* end() const {
		return &elem[nr];
	}

	bool operator!= (Map<K, V> map)
	{
		if (nr != map.nr)
			return false;
		for (int i = 0; i < nr; i++) {
			if (elem[i].key != map.elem[i].key)
				return false;
			if (elem[i].value != map.elem[i].value)
				return false;
		}
	}



};
int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [ key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto [ key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}
