
#include "gtest/gtest.h"
#include "../TaskList.h"
class TaskSuite : public ::testing::Test {


protected:
    virtual void SetUp() {
        L.setDescription("Descrizione");
        L.setTitle("Titolo");
        T->AddTask(L);
        T->save();
    }
    TaskList *T= new TaskList();
    Task L;
};

TEST_F(TaskSuite,LoadTest){
    T->load();
    ASSERT_EQ("Descrizione",T->getTask(0).getDescription());
    ASSERT_EQ("Titolo",T->getTask(0).getTitle());
}