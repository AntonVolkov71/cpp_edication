#include "people.h"

#include <stdexcept>


Person::Person(const std::string &name, int age, Gender gender): name_(name), age_(age), gender_(gender) {
}

const std::string &Person::GetName() const {
    return name_;
}

int Person::GetAge() const {
    return age_;
}

Gender Person::GetGender() const {
    return gender_;
}

Programmer::Programmer(const std::string &name, int age, Gender gender)
    : Person(name, age, gender) {
}


void Programmer::AddProgrammingLanguage(ProgrammingLanguage language) {
    languages_.insert(language);
}

bool Programmer::CanProgram(ProgrammingLanguage language) const {
    return languages_.count(language) > 0;
}

Worker::Worker(const std::string &name, int age, Gender gender)
    : Person(name, age, gender) {
}

void Worker::AddSpeciality(WorkerSpeciality speciality) {
    specialities_.insert(speciality);
}

bool Worker::HasSpeciality(WorkerSpeciality speciality) const {
    return specialities_.count(speciality) > 0;
}
