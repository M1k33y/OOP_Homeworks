#include <iostream>
#include <exception>
using namespace std;
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
   
};

template <class T>
class Array;

template<class T>
class ArrayIterator
{
private:
    int Current;
    Array  <T> A();
    // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator()
    {
        Current = 0;
        
    }
    ArrayIterator& operator ++ ()
    {
        Current++;
        return *this;
    }
    ArrayIterator& operator -- ()
    {
        Current--;
        return *this;
    }
    bool operator==(ArrayIterator<T>&otherArrayIterator)
    {
        if (A == otherArrayIterator.A && Current == otherArrayIterator.Current)
            return true;
        return false;
    }
    bool operator!=(ArrayIterator<T>& otherArrayIterator)
    {
        if (A == otherArrayIterator.A && Current == otherArrayIterator.Current)
            return false;
        return true;
    }
    T* GetElement()
    {
        if (Current < 0 || Current >= A.GetSize())
            return nullptr;

        return A[Current];
    }
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array()
    {
        Capacity = 0;
        Size = 0;
        List = new T * [Capacity];
    }
    // Lista nu e alocata, Capacity si Size = 0
    ~Array()
    {
        delete[] List;
        Size = 0;
        Capacity = 0;
    }
    // destructor
    Array(int capacity)
    {
        Capacity = capacity;
        Size = 0;
        List = new T * [Capacity];
    }
    // Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray)
    {
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;

        for (int i = 0; i < this->Size; i++)
            List[i] = otherArray.List[i];
    }
    // constructor de copiere

    T& operator[] (int index)
    {
        try
        {
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range");
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }

        return *List[index];

    }

    // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem)
    {

        if (Size >= Capacity)
            Capacity++;

        List[Size++] = new T(newElem);
        return *this;

    }
    // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem)
    {
        try
        {
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range la inserare elem");
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }

        if (index < Size)
        {
            for (int i = Size; i >= index; i--)
                List[i] = List[i - 1];
            List[index] = new T(newElem);
            Size++;
        }
        else if (index == Size)
        {
            List[index] = new T(newElem);
            Size++;
        }
        else if (index > Size)
        {
            for (int i = Size; i < index; i++)
                List[i] = new T();
            List[index] = new T(newElem);
            Size = index + 1;
        }
        return *this;
    }
    // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T>& otherArray)
    {
        try
        {
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range la inserare Array");
            if (index + otherArray.Size > this->Capacity)
                throw out_of_range("Index out of range la inserare Array, dim otherArray prea mare");
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }


        for (int i = 0; i < otherArray.Size; i++)
            Insert(index + i, *otherArray.List[i]);
        return *this;

    }
    // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index)
    {
        try
        {
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range la stergere");

        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }

        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        Size--;
        return *this;

    }
    // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    void operator=(const Array<T>& otherArray)
    {
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;

        for (int i = 0; i < Size; i++)
            List[i] = otherArray.List[i];

    }

    bool operator==(const Array<T>& otherArray)
    {
        if (this->Size != otherArray.Size)
            return false;
        for (int i = 0; i < Size; i++)
            if (List[i] != otherArray.List[i])
                return false;
        return true;

    }

    void Sort()
    {
        for (int i = 0; i < Size; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }
    // sorteaza folosind comparatia intre elementele din T

    
    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i],*List[j])>0)
                    swap(List[i], List[j]);
    }
    // sorteaza folosind o functie de comparatie

    void Sort(Compare* comparator)
    {
        for (int i = 0; i < Size; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i],List[j]))
                    swap(List[i], List[j]);

    }
    
    
    // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem)
    {
        int st=0, dr=Size-1,mid=0;

        while (st <= dr)
        {
            mid = st + (dr-st)/ 2;
            if (*List[mid] == elem)
                return mid;
            if (*List[mid] < elem)
                st = mid + 1;
            else
                dr = mid - 1;
        }
        return -1;


    }
    // cauta un element folosind binary search in Array

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int st = 0, dr = Size - 1, mid = 0;

        while (st <= dr)
        {
            mid = st + (dr - st) / 2;
            if (compare(*List[mid], elem)==0)
                return mid;
            if (compare(*List[mid], elem)<0)
                st = mid + 1;
            else
                dr = mid - 1;
        }
        return -1;
    }
    //  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator)
    {
        int st = 0, dr = Size - 1, mid = 0;

        while (st <= dr)
        {
            mid = st + (dr - st) / 2;
            if (comparator->CompareElements(List[mid], (void*)&elem)==0)
                return mid;
            if (comparator->CompareElements(List[mid], (void*) & elem)<0)
                st = mid + 1;
            else
                dr = mid - 1;
        }
        return -1;
    }
    //  cauta un element folosind binary search si un comparator

    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
    }
   
    // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i],elem)==0)
                return i;
    }
    //  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
                return i;
    }
    //  cauta un element folosind un comparator

    int GetSize()
    {
        return this->Size;
    }
    int GetCapacity()
    {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        ArrayIterator<T> start;
        start.Current = 0;
        return start;
    }
    ArrayIterator<T> GetEndIterator()
    {
        ArrayIterator<T> finish;
        finish.Current = Size;
        return finish;
    }
};
template<class T>
int compare(const T& x, const T& y)
{
    if (x > y)
        return 1;
    else if (x < y)
        return -1;

    return 0;
}
template<class T>
class Compare2 : public Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) override
    {
        T* x = static_cast<T*>(e1);
        T* y = static_cast<T*>(e2);
        if (*x > *y)
            return 1;
        else if (*x < *y)
            return -1;
        return 0;
    }
};

int main()
{
    Array<double> A(50);
    Array<double>B(5);
    Compare2 <double> comp;
    A += 10;
    A += 30;
    A += 20;
    A += 40;
    A += 50;
    A += 20;
    A += 70;
    A += 80;
    A += 8;
    
    B += 1;
    B += 2;
    B += 3;

    A.Sort(&comp);
    A.Sort(compare);
    A.Sort();
    cout << "TESTE SORTARI:" << endl;
    for (int i = 0; i < A.GetSize(); i++)
        cout << i << " " << A[i] << endl;

    cout << "TESTE CAUTARI:"<<endl;
    cout << A.BinarySearch(80)<<" "<<A.Find(80) << endl;
    cout << A.BinarySearch(40, compare) <<" "<< A.Find(40,compare)<< endl;
    cout << A.BinarySearch(20, &comp) <<" " << A.Find(20,&comp)<< endl;
    cout << endl;

    cout << "TESTE INSERT/DELETE:" << endl;
    A.Insert(4, B);
   // A = B;
    A.Delete(2);
    
    for (int i = 0; i < A.GetSize(); i++)
        cout << i<<" "<<A[i] << endl;

}
