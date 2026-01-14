#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>

#include "cpup/io.h"
#include "cpup/vec.h"

typedef enum {
    TODO = 0,
    INPROGRESS = 1,
    DONE = 2
} TASK_STATUS;

typedef struct {
    const char* name;
    TASK_STATUS status;
} Task;

const unsigned int DEFAULT_TASK_CAPACITY = 1000;
Task* tasks;

void list_tasks();
void add_task();
void remove_task(int _index);

int main(int _argc, char* _argv[])
{
    vec_init(&tasks, DEFAULT_TASK_CAPACITY, sizeof(Task));

    int should_loop = 1;

    while(should_loop == 1)
    {
        int s = request_int("1. List\n2. Add\n3. Remove\n4. Mark Task\n5. Exit\n");

        switch (s) {
            case 1:
                list_tasks();
                break;
            case 2:
                add_task();
                break;
            case 3:
                remove_task(request_int("Enter Tasks ID"));
                break;
            case 4:
                int index = request_int("Enter Tasks ID");
                int status = request_int("Enter Status 0. TODO 1. INPROGRESS 2. DONE");
                
                if (0 > index || vec_count(&tasks) <= index)
                    continue;
                if (status < 0 || 2 < status)
                    continue;

                tasks[index].status = status;
                break;
            case 5:
                should_loop = 0;
                break;
            default:
                break;
        };
    }

    // clean up c str
    while (vec_count(&tasks) > 0)
        remove_task(vec_count(&tasks) - 1);

    vec_free(&tasks);
    return 0;
}

void list_tasks()
{
    for (int i = 0; i < vec_count(&tasks); i++)
        printf("%i Task Name %s Status: %i\n", i, tasks[i].name, tasks[i].status);
}

void add_task()
{
    Task task;
    task.name = request_string("Task");
    task.status = TODO;

    vec_add(&tasks, &task);
}

void remove_task(int _index)
{
    if (0 > _index || vec_count(&tasks) <= _index)
        return;
    
    free(tasks[_index].name);

    vec_remove_at(&tasks, _index);
}
