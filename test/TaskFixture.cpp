
#include "gtest/gtest.h"
#include "../TaskCollection.cpp"
#include "ctime"


class TaskSuite : public ::testing::Test {


protected:
    virtual void SetUp() {
        date.tm_year = 112;
        date.tm_mon = 10;
        date.tm_mday = 9;
        L.setDescription("Descrizione");
        L.setTitle("Titolo");
        L.setDate(date);
        TL.setTitle("Titolo Lista");
        T->AddTaskList(TL);
        T->getTaskList(0).AddTask(L);
        T->save();
    }
    TaskCollection *T= new TaskCollection("Titolo Collezione");
    TaskList TL;
    Task L;
    struct tm date;

};

TEST_F(TaskSuite,LoadTest){
    T->load();

    ASSERT_EQ("Titolo Collezione",T->getTitle());
    ASSERT_EQ("Titolo Lista",T->getTaskList(0).getTitle());
    ASSERT_EQ("Titolo",T->getTaskList(0).getTask(0).getTitle());
    ASSERT_EQ("Descrizione",T->getTaskList(0).getTask(0).getDescription());
    ASSERT_EQ(9,T->getTaskList(0).getTask(0).getDate().tm_mday);
    ASSERT_EQ(10,T->getTaskList(0).getTask(0).getDate().tm_mon);
    ASSERT_EQ(112,T->getTaskList(0).getTask(0).getDate().tm_year);
}