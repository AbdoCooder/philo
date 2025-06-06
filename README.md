# 🍝 Philosophers

Welcome to `philo`, a concurrency-focused simulation of the classic Dining Philosophers Problem. This project dives deep into process synchronization, thread management, and mutexes using only low-level tools available in C. Built under strict 42 coding standards and without external libraries, this is a true test of threading discipline.

## 🚀 Features

* 🤴 Philosophers eat, sleep, and think in proper cycles
* ⚖️ Precise timing control for life and death simulation
* 🛏️ Mutex-based fork handling to prevent race conditions
* ⏱ Accurate timestamped state logging
* 🚫 No global variables allowed
* 🧪 Death detection within 10ms margin
* ⚠️ Manual memory management (no leaks allowed)

## 🎖️ Bonus Features (if unlocked)

> Bonuses are only considered if the mandatory part is flawless.

* ⚔️ Philosopher processes instead of threads
* ⚖️ Semaphores instead of mutexes
* 🚪 Forks placed centrally with access managed via semaphores
* 🌁 Multiple process management using `fork()` and `waitpid()`

## 🔢 Program Arguments

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

* `number_of_philosophers`: Number of philosophers and forks
* `time_to_die`: Time (ms) before a starving philosopher dies
* `time_to_eat`: Time (ms) taken to eat (holding both forks)
* `time_to_sleep`: Time (ms) spent sleeping after eating
* `number_of_times_each_philosopher_must_eat`: *(optional)* Simulation ends if all have eaten this many times

## 📊 Example Output

```text
0 1 is thinking
5 1 has taken a fork
6 1 has taken a fork
7 1 is eating
17 1 is sleeping
27 1 is thinking
...
105 2 died
```

## 💪 Compilation

```bash
make          # Build mandatory (threads + mutexes)
make bonus    # Build bonus (processes + semaphores)
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Full rebuild
```

## 🧐 Concepts Practiced

* Thread creation and management (`pthread_create`, `pthread_join`)
* Mutex usage for resource protection (`pthread_mutex_lock`, `unlock`)
* Race condition prevention
* Accurate logging and printing without overlapping outputs
* Timestamp handling with `gettimeofday`
* Process forking and semaphore control (bonus)

## ⚙️ Dependencies

* POSIX threads (`pthread`)
* Time functions (`usleep`, `gettimeofday`)
* For bonus:

  * Process control (`fork`, `kill`, `waitpid`)
  * Semaphores (`sem_open`, `sem_post`, `sem_wait`, ...)

## 📂 Directory Structure

```
philo/
|-- Makefile
|-- *.c
|-- *.h

philo_bonus/
|-- Makefile
|-- *_bonus.c
|-- *_bonus.h
```

## 🔗 External Functions Allowed

```c
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join,
pthread_mutex_init, pthread_mutex_destroy,
pthread_mutex_lock, pthread_mutex_unlock

// Bonus Only:
fork, kill, exit, waitpid,
sem_open, sem_close, sem_post, sem_wait, sem_unlink
```

## 📃 Reference Reading

* [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
* [POSIX Threads Programming](https://man7.org/linux/man-pages/man7/pthreads.7.html)
* [Semaphore Tutorial](https://man7.org/linux/man-pages/man7/sem_overview.7.html)

---

> ⛨️ Built for 42cursus — Norminette approved. May the philosophers live long and prosper.
