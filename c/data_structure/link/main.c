#include "link.h"


int main()
{
    Link *list = create(10);

    change(list, 2);
    print(list);

    delet(list, 2);
    delet(list, 2);
    print(list);

    insert(list,7);
    print(list);

    destroy(list);

    return 0;
}
