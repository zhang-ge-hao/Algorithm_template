ll get_rand(ll lo,ll hi){
    static bool has_init = 0;
    if(!has_init){
        srand(time(0));
        has_init = 1;
    }
    return rand()%(hi-lo+1)+lo;
}
