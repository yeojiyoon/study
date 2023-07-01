using System;

class MainClass
{
    static void Main(String[] args)
    {
        Person P1 = new Person();
        P1.Name = "서준";

        P1.Eat();
    }
}

class Person 
{
    public string Name = "";
    public string Birthday = "";
    public void Eat()
    {
        Console.WriteLine(Name + "이 밥을 먹습니다");
    }
}