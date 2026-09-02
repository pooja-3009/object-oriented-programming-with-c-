#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================
// CONSTANTS
// ============================================================

const int MAX_CITIZENS = 50;
const int MAX_COMPLAINTS = 100;
const int MAX_TEAMS = 10;


// ============================================================
// CITIZEN CLASS
// ============================================================

class Citizen
{
private:
    int citizenId;
    string name;
    string phone;
    string address;

public:

    // Default Constructor
    Citizen()
    {
        citizenId = 0;
        name = "";
        phone = "";
        address = "";
    }

    // Parameterized Constructor
    Citizen(int id, string n, string p, string a)
    {
        citizenId = id;
        name = n;
        phone = p;
        address = a;
    }

    // Copy Constructor
    Citizen(const Citizen &c)
    {
        citizenId = c.citizenId;
        name = c.name;
        phone = c.phone;
        address = c.address;
    }

    int getId()
    {
        return citizenId;
    }

    string getName()
    {
        return name;
    }

    void display()
    {
        cout << "\nCitizen ID : " << citizenId;
        cout << "\nName       : " << name;
        cout << "\nPhone      : " << phone;
        cout << "\nAddress    : " << address << endl;
    }

    ~Citizen()
    {
        // Destructor
    }
};


// ============================================================
// COMPLAINT CLASS
// ============================================================

class Complaint
{
private:

    int complaintId;
    int citizenId;
    string category;
    string description;
    int urgency;
    int priorityScore;
    string status;
    string assignedTeam;

public:

    static int totalComplaints;
    static int activeComplaints;

    // Default Constructor
    Complaint()
    {
        complaintId = 0;
        citizenId = 0;
        category = "";
        description = "";
        urgency = 0;
        priorityScore = 0;
        status = "Pending";
        assignedTeam = "Not Assigned";
    }

    // Parameterized Constructor
    Complaint(int id, int cid, string cat,
              string desc, int urg)
    {
        complaintId = id;
        citizenId = cid;
        category = cat;
        description = desc;
        urgency = urg;
        priorityScore = calculatePriority();
        status = "Pending";
        assignedTeam = "Not Assigned";

        totalComplaints++;
        activeComplaints++;
    }

    // Copy Constructor
    Complaint(const Complaint &c)
    {
        complaintId = c.complaintId;
        citizenId = c.citizenId;
        category = c.category;
        description = c.description;
        urgency = c.urgency;
        priorityScore = c.priorityScore;
        status = c.status;
        assignedTeam = c.assignedTeam;
    }

    int calculatePriority()
    {
        int categoryScore = 0;

        if (category == "Pothole")
            categoryScore = 7;

        else if (category == "Streetlight")
            categoryScore = 6;

        else if (category == "Garbage")
            categoryScore = 5;

        else if (category == "Water Leakage")
            categoryScore = 8;

        else if (category == "Unsafe Public Space")
            categoryScore = 10;

        else
            categoryScore = 4;

        return urgency * 10 + categoryScore;
    }

    int getId()
    {
        return complaintId;
    }

    int getCitizenId()
    {
        return citizenId;
    }

    string getCategory()
    {
        return category;
    }

    string getStatus()
    {
        return status;
    }

    string getAssignedTeam()
    {
        return assignedTeam;
    }

    int getPriority()
    {
        return priorityScore;
    }

    void assignTeam(string team)
    {
        assignedTeam = team;
        status = "Assigned";
    }

    void updateStatus(string newStatus)
    {
        if (status != "Resolved" &&
            newStatus == "Resolved")
        {
            activeComplaints--;
        }

        status = newStatus;
    }


    // ========================================================
    // OPERATOR OVERLOAD 1
    // Compare Complaint Priority
    // ========================================================

    bool operator>(const Complaint &c)
    {
        return priorityScore > c.priorityScore;
    }


    // ========================================================
    // OPERATOR OVERLOAD 2
    // Compare Complaint Priority
    // ========================================================

    bool operator<(const Complaint &c)
    {
        return priorityScore < c.priorityScore;
    }


    void display()
    {
        cout << "\n------------------------------------";
        cout << "\nComplaint ID     : " << complaintId;
        cout << "\nCitizen ID       : " << citizenId;
        cout << "\nCategory         : " << category;
        cout << "\nDescription      : " << description;
        cout << "\nUrgency (1-5)    : " << urgency;
        cout << "\nPriority Score   : " << priorityScore;
        cout << "\nStatus           : " << status;
        cout << "\nAssigned Team    : " << assignedTeam;
        cout << "\n------------------------------------\n";
    }


    // Destructor
    ~Complaint()
    {
        // Complaint record finalized
    }
};


// Static Member Definitions
int Complaint::totalComplaints = 0;
int Complaint::activeComplaints = 0;


// ============================================================
// VIRTUAL BASE CLASS
// ============================================================

class MunicipalResource
{
protected:
    int resourceId;
    string resourceName;

public:

    MunicipalResource()
    {
        resourceId = 0;
        resourceName = "";
    }

    MunicipalResource(int id, string name)
    {
        resourceId = id;
        resourceName = name;
    }

    virtual void displayResource()
    {
        cout << "\nResource ID   : " << resourceId;
        cout << "\nResource Name : " << resourceName;
    }

    virtual ~MunicipalResource()
    {
    }
};


// ============================================================
// ABSTRACT BASE CLASS
// ============================================================

class ResponseTeam
{
protected:

    int teamId;
    string teamName;
    int workload;
    int capacity;

public:

    static int availableTeams;

    ResponseTeam()
    {
        teamId = 0;
        teamName = "";
        workload = 0;
        capacity = 0;
    }

    ResponseTeam(int id, string name, int cap)
    {
        teamId = id;
        teamName = name;
        workload = 0;
        capacity = cap;

        availableTeams++;
    }

    // PURE VIRTUAL FUNCTION
    virtual void respondToComplaint(Complaint &c) = 0;

    virtual string getSpecialization() = 0;

    virtual void displayTeam()
    {
        cout << "\nTeam ID        : " << teamId;
        cout << "\nTeam Name      : " << teamName;
        cout << "\nSpecialization : " << getSpecialization();
        cout << "\nWorkload       : " << workload;
        cout << "\nCapacity       : " << capacity;
    }

    string getTeamName()
    {
        return teamName;
    }

    int getWorkload()
    {
        return workload;
    }

    int getCapacity()
    {
        return capacity;
    }


    // ========================================================
    // OPERATOR OVERLOAD 3
    // Combine workloads
    // ========================================================

    int operator+(const ResponseTeam &team)
    {
        return workload + team.workload;
    }


    virtual ~ResponseTeam()
    {
        availableTeams--;
    }
};


int ResponseTeam::availableTeams = 0;


// ============================================================
// DIAMOND INHERITANCE SUPPORT CLASSES
// Virtual inheritance used
// ============================================================

class FieldOperations : virtual public MunicipalResource
{
protected:
    string operationArea;

public:

    FieldOperations()
    {
        operationArea = "General Field Operations";
    }

    FieldOperations(string area)
    {
        operationArea = area;
    }
};


class EmergencyOperations : virtual public MunicipalResource
{
protected:
    int responseLevel;

public:

    EmergencyOperations()
    {
        responseLevel = 1;
    }

    EmergencyOperations(int level)
    {
        responseLevel = level;
    }
};


// ============================================================
// SANITATION TEAM
// ============================================================

class SanitationTeam : public ResponseTeam
{
public:

    SanitationTeam(int id, string name, int cap)
        : ResponseTeam(id, name, cap)
    {
    }

    void respondToComplaint(Complaint &c)
    {
        workload++;
        c.assignTeam(teamName);

        cout << "\nSanitation Team assigned to Complaint "
             << c.getId() << endl;
    }

    string getSpecialization()
    {
        return "Garbage and Waste Management";
    }
};


// ============================================================
// ROAD MAINTENANCE TEAM
// ============================================================

class RoadMaintenanceTeam : public ResponseTeam
{
public:

    RoadMaintenanceTeam(int id, string name, int cap)
        : ResponseTeam(id, name, cap)
    {
    }

    void respondToComplaint(Complaint &c)
    {
        workload++;
        c.assignTeam(teamName);

        cout << "\nRoad Maintenance Team assigned to Complaint "
             << c.getId() << endl;
    }

    string getSpecialization()
    {
        return "Potholes and Road Damage";
    }
};


// ============================================================
// ELECTRICAL TEAM
// ============================================================

class ElectricalTeam : public ResponseTeam
{
public:

    ElectricalTeam(int id, string name, int cap)
        : ResponseTeam(id, name, cap)
    {
    }

    void respondToComplaint(Complaint &c)
    {
        workload++;
        c.assignTeam(teamName);

        cout << "\nElectrical Team assigned to Complaint "
             << c.getId() << endl;
    }

    string getSpecialization()
    {
        return "Streetlight and Electrical Failures";
    }
};


// ============================================================
// WATER TEAM
// ============================================================

class WaterTeam : public ResponseTeam
{
public:

    WaterTeam(int id, string name, int cap)
        : ResponseTeam(id, name, cap)
    {
    }

    void respondToComplaint(Complaint &c)
    {
        workload++;
        c.assignTeam(teamName);

        cout << "\nWater Team assigned to Complaint "
             << c.getId() << endl;
    }

    string getSpecialization()
    {
        return "Water Leakage and Pipeline Problems";
    }
};


// ============================================================
// PUBLIC SAFETY TEAM
// MULTIPLE INHERITANCE + VIRTUAL BASE CLASS
// ============================================================

class PublicSafetyTeam :
    public ResponseTeam,
    public FieldOperations,
    public EmergencyOperations
{
public:

    PublicSafetyTeam(int id, string name, int cap)
        : ResponseTeam(id, name, cap),
          MunicipalResource(id, name),
          FieldOperations("Public Areas"),
          EmergencyOperations(5)
    {
    }

    void respondToComplaint(Complaint &c)
    {
        workload++;
        c.assignTeam(teamName);

        cout << "\nPublic Safety Team assigned to Complaint "
             << c.getId() << endl;
    }

    string getSpecialization()
    {
        return "Unsafe Public Spaces and Emergency Safety";
    }
};


// ============================================================
// GLOBAL ARRAYS OF OBJECTS
// ============================================================

Citizen citizens[MAX_CITIZENS];
Complaint complaints[MAX_COMPLAINTS];

int citizenCount = 0;
int complaintCount = 0;


// ============================================================
// REGISTER CITIZEN
// ============================================================

void registerCitizen()
{
    if (citizenCount >= MAX_CITIZENS)
    {
        cout << "\nCitizen storage is full.\n";
        return;
    }

    int id;
    string name, phone, address;

    cout << "\nEnter Citizen ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Address: ";
    getline(cin, address);

    citizens[citizenCount] =
        Citizen(id, name, phone, address);

    citizenCount++;

    cout << "\nCitizen Registered Successfully!\n";
}


// ============================================================
// CHECK CITIZEN EXISTS
// ============================================================

bool citizenExists(int id)
{
    for (int i = 0; i < citizenCount; i++)
    {
        if (citizens[i].getId() == id)
            return true;
    }

    return false;
}


// ============================================================
// REGISTER COMPLAINT
// ============================================================

void registerComplaint()
{
    if (complaintCount >= MAX_COMPLAINTS)
    {
        cout << "\nComplaint storage is full.\n";
        return;
    }

    int complaintId;
    int citizenId;
    int urgency;
    int choice;

    string category;
    string description;

    cout << "\nEnter Complaint ID: ";
    cin >> complaintId;

    cout << "Enter Citizen ID: ";
    cin >> citizenId;

    if (!citizenExists(citizenId))
    {
        cout << "\nCitizen not found. Register citizen first.\n";
        return;
    }

    cout << "\nSelect Complaint Category:\n";
    cout << "1. Pothole\n";
    cout << "2. Streetlight\n";
    cout << "3. Garbage\n";
    cout << "4. Water Leakage\n";
    cout << "5. Unsafe Public Space\n";
    cout << "6. Other\n";

    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            category = "Pothole";
            break;

        case 2:
            category = "Streetlight";
            break;

        case 3:
            category = "Garbage";
            break;

        case 4:
            category = "Water Leakage";
            break;

        case 5:
            category = "Unsafe Public Space";
            break;

        default:
            category = "Other";
    }

    cin.ignore();

    cout << "Enter Description: ";
    getline(cin, description);

    cout << "Enter Urgency (1-5): ";
    cin >> urgency;

    complaints[complaintCount] =
        Complaint(complaintId,
                  citizenId,
                  category,
                  description,
                  urgency);

    complaintCount++;

    cout << "\nComplaint Registered Successfully!\n";
}


// ============================================================
// DISPLAY ALL COMPLAINTS
// ============================================================

void displayComplaints()
{
    if (complaintCount == 0)
    {
        cout << "\nNo complaints registered.\n";
        return;
    }

    for (int i = 0; i < complaintCount; i++)
    {
        complaints[i].display();
    }
}


// ============================================================
// FIND COMPLAINT INDEX
// ============================================================

int findComplaint(int id)
{
    for (int i = 0; i < complaintCount; i++)
    {
        if (complaints[i].getId() == id)
            return i;
    }

    return -1;
}


// ============================================================
// ASSIGN COMPLAINT USING POLYMORPHISM
// ============================================================

void assignComplaint(ResponseTeam *teams[])
{
    int complaintId;

    cout << "\nEnter Complaint ID: ";
    cin >> complaintId;

    int index = findComplaint(complaintId);

    if (index == -1)
    {
        cout << "\nComplaint not found.\n";
        return;
    }

    string category =
        complaints[index].getCategory();

    ResponseTeam *selectedTeam = nullptr;


    if (category == "Garbage")
        selectedTeam = teams[0];

    else if (category == "Pothole")
        selectedTeam = teams[1];

    else if (category == "Streetlight")
        selectedTeam = teams[2];

    else if (category == "Water Leakage")
        selectedTeam = teams[3];

    else if (category == "Unsafe Public Space")
        selectedTeam = teams[4];


    if (selectedTeam == nullptr)
    {
        cout << "\nNo suitable response team available.\n";
        return;
    }


    // Runtime Polymorphism
    selectedTeam->respondToComplaint(
        complaints[index]
    );
}


// ============================================================
// UPDATE COMPLAINT STATUS
// ============================================================

void updateComplaintStatus()
{
    int complaintId;
    int choice;

    cout << "\nEnter Complaint ID: ";
    cin >> complaintId;

    int index =
        findComplaint(complaintId);

    if (index == -1)
    {
        cout << "\nComplaint not found.\n";
        return;
    }

    cout << "\n1. Pending";
    cout << "\n2. Assigned";
    cout << "\n3. In Progress";
    cout << "\n4. Resolved";

    cout << "\nEnter New Status: ";
    cin >> choice;

    string status;

    switch (choice)
    {
        case 1:
            status = "Pending";
            break;

        case 2:
            status = "Assigned";
            break;

        case 3:
            status = "In Progress";
            break;

        case 4:
            status = "Resolved";
            break;

        default:
            cout << "\nInvalid choice.\n";
            return;
    }

    complaints[index].updateStatus(status);

    cout << "\nComplaint Status Updated Successfully!\n";
}


// ============================================================
// COMPARE TWO COMPLAINTS
// OPERATOR OVERLOADING DEMONSTRATION
// ============================================================

void compareComplaints()
{
    int id1, id2;

    cout << "\nEnter First Complaint ID: ";
    cin >> id1;

    cout << "Enter Second Complaint ID: ";
    cin >> id2;

    int index1 =
        findComplaint(id1);

    int index2 =
        findComplaint(id2);

    if (index1 == -1 ||
        index2 == -1)
    {
        cout << "\nOne or both complaints not found.\n";
        return;
    }


    if (complaints[index1] >
        complaints[index2])
    {
        cout << "\nComplaint "
             << id1
             << " has higher priority.\n";
    }

    else if (complaints[index1] <
             complaints[index2])
    {
        cout << "\nComplaint "
             << id2
             << " has higher priority.\n";
    }

    else
    {
        cout << "\nBoth complaints have equal priority.\n";
    }
}


// ============================================================
// DISPLAY TEAM WORKLOAD
// ============================================================

void displayTeamWorkload(ResponseTeam *teams[],
                         int teamCount)
{
    cout << "\n========== RESPONSE TEAM WORKLOAD ==========\n";

    for (int i = 0; i < teamCount; i++)
    {
        teams[i]->displayTeam();

        cout << "\n--------------------------------\n";
    }


    // Demonstrating overloaded + operator

    if (teamCount >= 2)
    {
        int combinedWorkload =
            (*teams[0]) + (*teams[1]);

        cout << "\nCombined workload of first two teams: "
             << combinedWorkload
             << endl;
    }
}


// ============================================================
// GENERATE CIVIC REPORT
// ============================================================

void generateReport()
{
    int pending = 0;
    int assigned = 0;
    int progress = 0;
    int resolved = 0;

    for (int i = 0; i < complaintCount; i++)
    {
        string status =
            complaints[i].getStatus();

        if (status == "Pending")
            pending++;

        else if (status == "Assigned")
            assigned++;

        else if (status == "In Progress")
            progress++;

        else if (status == "Resolved")
            resolved++;
    }


    cout << "\n";
    cout << "============================================\n";
    cout << "       SMART CIVIC RESPONSE REPORT\n";
    cout << "============================================\n";

    cout << "\nTotal Citizens Registered : "
         << citizenCount;

    cout << "\nTotal Complaints          : "
         << Complaint::totalComplaints;

    cout << "\nActive Complaints         : "
         << Complaint::activeComplaints;

    cout << "\nResolved Complaints       : "
         << resolved;

    cout << "\nPending Complaints        : "
         << pending;

    cout << "\nAssigned Complaints       : "
         << assigned;

    cout << "\nIn Progress Complaints    : "
         << progress;

    cout << "\nAvailable Response Teams  : "
         << ResponseTeam::availableTeams;

    cout << "\n============================================\n";
}


// ============================================================
// DISPLAY CITIZENS
// ============================================================

void displayCitizens()
{
    if (citizenCount == 0)
    {
        cout << "\nNo citizens registered.\n";
        return;
    }

    for (int i = 0;
         i < citizenCount;
         i++)
    {
        citizens[i].display();
    }
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    // --------------------------------------------------------
    // OBJECTS CREATED FOR DIFFERENT RESPONSE TEAMS
    // --------------------------------------------------------

    SanitationTeam sanitation(
        1,
        "Clean City Team",
        20
    );

    RoadMaintenanceTeam road(
        2,
        "Road Repair Team",
        15
    );

    ElectricalTeam electrical(
        3,
        "Electrical Maintenance Team",
        15
    );

    WaterTeam water(
        4,
        "Water Supply Team",
        15
    );

    PublicSafetyTeam safety(
        5,
        "Public Safety Response Team",
        10
    );


    // --------------------------------------------------------
    // BASE CLASS POINTER ARRAY
    // Runtime Polymorphism
    // --------------------------------------------------------

    ResponseTeam *teams[5];

    teams[0] = &sanitation;
    teams[1] = &road;
    teams[2] = &electrical;
    teams[3] = &water;
    teams[4] = &safety;


    int choice;


    do
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << " SMART CIVIC COMPLAINT & SAFETY SYSTEM\n";
        cout << "============================================\n";

        cout << "\n1. Register Citizen";
        cout << "\n2. Display Citizens";
        cout << "\n3. Register Complaint";
        cout << "\n4. Display Complaints";
        cout << "\n5. Assign Complaint to Response Team";
        cout << "\n6. Update Complaint Status";
        cout << "\n7. Compare Complaint Priorities";
        cout << "\n8. Display Team Workload";
        cout << "\n9. Generate Civic Response Report";
        cout << "\n0. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:
                registerCitizen();
                break;

            case 2:
                displayCitizens();
                break;

            case 3:
                registerComplaint();
                break;

            case 4:
                displayComplaints();
                break;

            case 5:
                assignComplaint(teams);
                break;

            case 6:
                updateComplaintStatus();
                break;

            case 7:
                compareComplaints();
                break;

            case 8:
                displayTeamWorkload(
                    teams,
                    5
                );
                break;

            case 9:
                generateReport();
                break;

            case 0:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    }
    while (choice != 0);


    return 0;
}