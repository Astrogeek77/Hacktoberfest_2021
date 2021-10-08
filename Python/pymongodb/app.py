import pymongo
import json
import values

client = pymongo.MongoClient(values.link)
db = client.newdatabase

def insert_data():
    print("Insert to database: ")
    name = input("Name: ")
    branch = input("Branch: ")
    year = input("Year: ")
    r = db.students.insert_one({"name":name,"branch":branch,"year":year})
    if r.acknowledged:
        print("Inserted "+str(r.inserted_id))
    else:
        print("Insertion failed")

def clear_database():
    db.students.delete_many({})

def read_database():
    res = db.students.find()
    for r in res:
        print(r)

def read_data(paramname,paramvalue):
    res = db.students.find({paramname:paramvalue})
    for r in res:
        name = r['name']
        branch = r['branch']
        year = r['year']
        print(f"Name: {name}\nBranch: {branch}\nYear: {year}")

def update_data(targetparamname,targetparamvalue,newparamname,newparamvalue):
    res = db.students.update_one({targetparamname:targetparamvalue},{"$set":{newparamname:newparamvalue}})
    if res.acknowledged:
        if res.matched_count>0:
            print("Update successful")
        else:
            print("Document not found")
    else:
        print("Failed to update")

def delete_data(paramname,paramvalue):
    res = db.students.delete_one({paramname:paramvalue})
    if res.acknowledged:
        if res.deleted_count>0:
            print("Deletion successful")
        else:
            print("Document not found")
    else:
        print("Failed to delete")


while True:
    c = int(input("Choose operation: 1.Insert 2.Update 3.Delete 4.Delete all 5.Read 6.Read all 7.Exit\n"))
    if c==1:
        insert_data()
    if c==2:
        string= input("Enter name and old value of parameter (name/branch/year:value)").split(":")
        targetparamname = string[0]
        targetparamvalue = string[1]
        string= input("Enter name and new value of parameter(name/branch/year:value)").split(":")
        newparamname = string[0]
        newparamvalue = string[1]
        update_data(targetparamname,targetparamvalue,newparamname,newparamvalue)
    if c==3:
        string= input("Enter name and value of parameter to delete by (name/branch/year:value)").split(":")
        paramname = string[0]
        paramvalue = string[1]
        delete_data(paramname,paramvalue)
    if c==4:
        clear_database()
    if c==5:
        string= input("Enter name and value of parameter to search by (name/branch/year:value)").split(":")
        paramname = string[0]
        paramvalue = string[1]
        read_data(paramname,paramvalue)
    if c==6:
        read_database()
    if c==7:
        break






