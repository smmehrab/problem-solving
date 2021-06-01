/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
void bfs (int start){
    deque <int > Q;
    Q.push_back( start);
    distance[ start ] = 0;

    while( !Q.empty ()){
        int v = Q.front( );
        Q.pop_front();

        for( int i = 0 ; i < edges[v].size(); i++){
            if(distance[ edges[ v ][ i ].first ] > distance[ v ] + edges[ v ][ i ].second ){
                distance[ edges[ v ][ i ].first ] = distance[ v ] + edges[ v ][ i ].second;

                if(edges[ v ][ i ].second == 0)
                    Q.push_front( edges[ v ][ i ].first);

                else
                    Q.push_back( edges[ v ][ i ].first);
            }
        }
    }
}
