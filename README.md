# GoBang_Battle

Here I used Professor HuanchenZhang's gobang template, and extend it to a real $\textbf{human-robot gobang}$  !

I add several files with `bot` in their names, also committed some subtle changes to other files.



# To Run

Run these lines under Linux to play.
```
cd build
make
./main
```

By default, it's `Human-Robot3` mode.

You can also run with parameters like:
```
./main p1 p2
```
Where `p1 p2` are indexes indicating players' type: 
Player Index    | Player Type
-------- | -----
0  | Human ( KeyboardAgent )
1  | Robot1 ( Very Simple )
2  | Robot2 ( Also Simple )
3  | Robot3 ( Min-max Search )

For example, the following comand:
```
./main 1 2
```
means to watch Robot1 play against Robot2.
```
./main 0 0
```
means to play with your friend.

# To Play

**Use WASD to move, Enter to place!**

As a Human ( KeyboardAgent ) , the big `X` is your handler. You should move it to the right place using **WASD** and place your piece with **Enter**.

The yellow marked piece simply means the most recently taken one.

It's simple.


# What even more handsome -

### Hey, you can submit your own robot to fight, with human, or with other robots !

Your robot should derive from `class strategy` in file `include\strategy.h`, which requires 
to implement only one function `get_pos()`.

You can check `Human` 's `get_pos()` in `include\strategy.cpp` for reference.

**Sorry that this page is not yet complete, 但勉强能看懂吧应该。。。**
