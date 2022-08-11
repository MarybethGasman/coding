/*
 * msg.x: Remote message printing protocol
 */ 
struct number {
    int x;
    int y;
};

program ADDPROG {
    version ADDVERS {
        int add(number) = 1;
    } = 1;
} = 0x23451111;