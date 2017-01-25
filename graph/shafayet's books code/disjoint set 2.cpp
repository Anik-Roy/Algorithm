struct DisjointSet
{
    void make_set( int n )
    {
        numSets = n;
        setSize.assign( n, 1 );

        for( int i = 0; i < n; i++ )
        {
            Rank[i] = 0;
            p[i] = i;
        }
    }

    int findSet( int i )
    {
        return ( p[i] == i ) ? i : ( p[i] = findSet( p[i] ) );
    }

    bool isSameSet( int i, int j )
    {
        return findSet(i) == findSet(j);
    }

    void unionSet( int i, int j )
    {
        if( !isSameSet( i, j ) )
        {
            numSets--;
            int x = findSet(i), y = findSet(j);

            if( Rank[x] > Rank[y] )
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];

                if( Rank[x] == Rank[y] )
                {
                    Rank[y]++;
                }
            }
        }
    }

    int numofdisjointset()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }

} UF;

int main()
