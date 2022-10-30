import yaml
from yaml.loader import SafeLoader
import matplotlib.pyplot as plt
from matplotlib import animation

# Create plot
fig, ax = plt.subplots()
ax.set_aspect('equal')

# Set limits and axis label
ax.set_xlim([-10, 10])
ax.set_ylim([-10, 10])
ax.set_xlabel("X axis")
ax.set_ylabel("Y axis")

# Draw x and y axis line 
ax.axhline(y=0, color='k')
ax.axvline(x=0, color='k')



class ArmTrajectory():
    def __init__(self, file_path):
        with open(file_path) as f:
            self.data = yaml.load(f, Loader=SafeLoader)

        self.init_pose = self.data["trajectory"][0]
        self.trajectory = self.data["trajectory"]
        self.draw_arm(self.init_pose)
        self.traj_length = len(self.data["trajectory"])

    def draw_arm(self, pose):
        # Draw arm base
        base = plt.Circle((0, 0), 0.5, color='b')
        ax.add_patch(base)

        # Draw joints and arm
        p1 = [0, 0]; 
        for joint_pose in pose:
            print(joint_pose)
            joint = plt.Circle(joint_pose, 0.5, color='b')
            ax.add_patch(joint)

            # Draw arm
            p2 = joint_pose
            x, y = [p1[0], p2[0]], [p1[1], p2[1]]
            plt.plot(x, y, color='c')
            p1 = p2

    def draw(self):
        for arm_pose in self.trajectory:
            self.draw_arm(arm_pose)

def main():
    file_path = './arm_traj.yaml'
    arm_traj = ArmTrajectory(file_path)

    arm_traj.draw()

    plt.savefig('example.png')
    plt.show()   

    # anim = animation.FuncAnimation(fig, arm_traj.draw_arm, frames=arm_traj.traj_length, interval=100, repeat=False, save_count=arm_traj.traj_length)
    # writergif = animation.PillowWriter(fps=30)
    # anim.save('arm_traj.gif', writer=writergif)

if __name__ == "__main__":
    main()

