# Mother
Mother is a specialized version control system intended for development and deployment of configurations and other files onto virtualized or baremetal networks of systems. It utilizes trunk-based development concepts to streamline the development process, while preserving the state and uniqueness of each machine in your Mother system by using a unique branch for each target machine's configurations. It also performs well with projects that have multiple inter-dependent pieces of software that are not well suited for microservices architectures.

Mother is not intended for projects with a large number of developers, and the architecture does not scale well with organization size. A properly run Mother Project is used and maintained by only one software or integration team.

## Mother Architecture
Each Mother Project has two separate systems which work together to enable it to be an ideal version control format for both developing and deploying configurations (or software).

### I and You
In Mother, I is your local copy of the Project, and You is the remote copy of your Project. To pull an existing Mother project, use the command:
```Mother May I <projectname>```
This will update I with the Mother May of the project.

```Mother I <projectname>```
Will sync your local project with both May and Ship from your project.

```Mother Ship I <projectname>```
Will sync only your Ship with your project. This is ideal for commissioning engineers. May and Ship also have independently operating permissions.

### Mother May
Mother May is a traditional, diff-based trunk development branch that is architected as a tree of individual cradles.

#### Cradles
A cradle is a standalone repository. It typically represents the code or configurations that will be deployed on a specific type of machine or container in your project. While these are standalone, you can build a tree of Parent-Child-Grandchild relationships between Cradles within Mother May.

Suppose you have 3 types of target machines, A, B, which is a child of A, and C, which is also a child of A. To make a change to machine type C, you first make the change, then type:
```Mother May You A-C```
This pushes your local change to the C Cradle to Mother May as a single commit. As a result, only one repository may be updated in a Mother May at a time, resulting in easy management and revision of feature commits.

#### Gold Stars
Mother May has two project tracking indices - Head, which is the most recent commit to Mother May, and Gold Star, which is the most recent approved commit of May. Gold Stars function similarly to a pull request in traditional SCM, and a commit must go through an approval process to receive a Gold Star. Jenkins integration is pending for Gold Stars.

### Mother Ship
Mother Ship is a non-diff-based production branch that is intended to house only archived and deployed versions of what is being developed in Mother May. Each commit in Mother Ship is a standalone archive, meaning it is a copy of all files as they were at a particular Gold Star in Mother May. The key difference here is that Mother Ship is not diff based, meaning that regardless of what changes happen to old version history in Mother May, a Mother Ship commit will never change. This is an ideal representation of recording what has been deployed to a container or physical machine in the past.

In fact, Mother Ship comes with a feature to deploy configurations or software directly to a tree of target machines. Simply create a hosts.yml file in the root directory of Mother Ship and run the command
```Mother Ship <cradlename>```
and every cradle below cradlename in your tree will have its contents transferred to the hosts in your yml file that match that cradle type.

Mother Ship is versatile. You can deploy a release to a specific set of cradles only. When you release software or configurations to Mother Ship, all of their children will also be released. Suppose you have cradles A, B, and C, where B and C are children of A, and cradles D and E, where D is the parent of E. Suppose also that cradles B, D, and E are ready for release, but A and C need more work. By running
```Mother Ship You B,D```
you will release B, D, and E from Mother May to Mother Ship as a commit. 

