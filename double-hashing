/* *
 * Program - Double Hashing, Code by- Satyarth Agrahari
 * ---------------------------------------------------------
 * This program is c implementation of double hashing.
 * The first hash function is for getting the key value
 * and the other for getting the offset. Try to make
 * table size a prime to reduce repetition of cell during
 * offset traversal.
 */

 #include <stdio.h>
 #include <string.h>

 // choose table size to be prime number.
 // this reduces chances of collision.
 #define SIZE 11
 #define EMPTY -999999          // empty condition
 #define DELETE -9999999        // delete condition

 int hash_function(int );       // the hash function to calucate the position of data
 int offset(int );              // the offset value during collision
 void insert(int *, int);       // method to insert data into hash table
 void display(int *);           // to display data at all index
 void del(int *, int);          // to delete data value at position specified by hash map
 void search(int *, int);       // to search for a data in the hash table

 int main()
 {
        int hash[SIZE];
        int n, q, i, data;
        char str[30];

        // marking the hash table empty
        for (i = 0; i < SIZE; i++) {
                hash[i] = EMPTY;
        }

        // driver function
        scanf("%s", str);
        while (strcmp(str, "exit") != 0) {
                if (strcmp(str, "insert") == 0) {
                        scanf("%d", &data);
                        insert(hash, data);
                } else if (strcmp(str, "display") == 0) {
                        display(hash);
                } else if (strcmp(str, "delete") == 0) {
                        scanf("%d", &data);
                        del(hash, data);
                } else if (strcmp(str, "search") == 0) {
                        scanf("%d", &data);
                        search(hash, data);
                }

                scanf("%s", str);
        }

        return 0;
 }

 /* *
 * hash_function()
 * ------------------------------------------------------------
 * The following returns mapped key location of the data to be
 * inserted.
 */
 int hash_function(int data)
 {
        return (data % SIZE);
 }

/* *
 * offset()
 * -------------------------------------------------------------
 * This function returns the offset to be increased during
 * collision condition.
 */
 int offset(int data)
 {
        // step function to increase
        return (8 - (data % 8));
 }

 /* *
 * insert()
 * ------------------------------------------------------------
 * The following returns inserts the data into the desired mapped
 * location. In case of collision, the insert position of data is
 * handled by method of using a offset function.
 */
 void insert(int hash[], int data)
 {
        int key, count = 0;
        key = hash_function(data);      //location predicted to map data

        // if the position is vacant, enter data
        if (hash[key] == EMPTY) {
                hash[key] = data;
        } else {
                // search for next vacant position. It can be either an
                // empty position or a position from where a data was deleted
                while ((hash[key] != EMPTY) && (hash[key] != DELETE)) {

                        // increasing steps by offset value
                        key = (key + offset(data)) % SIZE;
                        count++;

                        // if we could not find a space after whole table iteration
                        // means that the table is full
                        if (count == SIZE) {
                                printf("Table filled, cannot enter data.\n");
                                return;
                        }
                }
                hash[key] = data;
        }
 }

 /* *
 * display()
 * ------------------------------------------------------------
 * The following function displays the data at all the index in
 * the hash table. The first line will be index, and the next
 * will be data.
 */
 void display(int hash[])
 {
        int i;

        // for displaying the index
        for (i = 0; i < SIZE; i++) {
                printf("%d\t", i);
        }
        printf("\n");

        // for displaying the data at the index
        for (i = 0; i < SIZE; i++) {
                if ((hash[i] != DELETE) && (hash[i] != EMPTY)) {
                        printf("%d\t", hash[i]);
                } else {
                        printf("\t");
                }
        }
        printf("\n");
 }

 /* *
 * del()
 * ------------------------------------------------------------
 * The following function searches for data and then deletes.
 * The marker is kept at that position to mark location delete
 * and not empty.
 */
 void del(int hash[], int data)
 {
        int key, count = 0;
        key = hash_function(data);

        // search for data
        while (hash[key] != data) {

                // increasing step value equal to offset
                key = (key + offset(data)) % SIZE;
                count++;

                // if the whole table is traversed or if a empty
                // location is reached, It means that the data is
                // not present at that location, so we simply return
                if ((count == SIZE) || (hash[key] == EMPTY)) {
                        printf("Data not found\n");
                        return;
                }
        }

        // mark the position as delete, not empty
        // other wise the search function will have
        // problem
        hash[key] = DELETE;
 }

 /* *
 * search()
 * ------------------------------------------------------------
 * The following function searches for a piece of data in the
 * hash table
 */
 void search(int hash[], int data)
 {
        int key, count = 0;
        key = hash_function(data);

        // searching for data in table
        while (hash[key] != data) {
                key = (key + offset(data)) % SIZE;
                count++;

                // if the whole table is traversed or a empty space is found
                // this means data is not present and we return
                if ((count == SIZE) || (hash[key] == EMPTY)) {
                        printf("Data not found\n");
                        return;
                }
        }

        // if the if condition does not satisfy
        // it implies that the data is present
        printf("Data found in table\n");
 }

