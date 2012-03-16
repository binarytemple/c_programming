/*
 * redis_test.c
 *
 *  Created on: Mar 16, 2012
 *      Author: bryan
 */
#include <hiredis/hiredis.h>
#include <time.h>


int main(int argc, char **argv) {

    time_t sec;
    sec = time (NULL);



	redisContext *c = redisConnect("127.0.0.1", 6379);
	int *	reply = redisCommand(c, "AUTH yourmotherhasapenisyesshehas");
	reply = redisCommand(c, "SET farty barty ");
	printf("Got that context!");
}


//
//if (c->err) {
//    printf("Error: %s\n", c->errstr);
//    // handle error
//}
//
//Sending commands
//
//There are several ways to issue commands to Redis. The first that will be introduced is redisCommand. This function takes a format similar to printf. In the simplest form, it is used like this:
//
//reply = redisCommand(context, "SET foo bar");
//
//The specifier %s interpolates a string in the command, and uses strlen to determine the length of the string:
//
//reply = redisCommand(context, "SET foo %s", value);
//
//When you need to pass binary safe strings in a command, the %b specifier can be used. Together with a pointer to the string, it requires a size_t length argument of the string:
//
//reply = redisCommand(context, "SET foo %b", value, valuelen);
//
//Internally, Hiredis splits the command in different arguments and will convert it to the protocol used to communicate with Redis. One or more spaces separates arguments, so you can use the specifiers anywhere in an argument:
//
//reply = redisCommand("SET key:%s %s", myid, value);


