import os
import graphviz
# os.system("./nfa2")

# Create a Graphviz object from the DOT file
graph = graphviz.Source.from_file('fsm.gv', format='png')
current_directory = os.getcwd()

# Combine the current directory and the output image name to get the full path
output_image_path = os.path.join(current_directory, "DFA")
# Save the graph as an image
graph.render(output_image_path, format='png', cleanup=True)
# dot = graphviz.Digraph(comment='The Round Table')
# dot.render('fsm.gv', view=True)
# os.system("dot -Tpng fsm.gv -o my.pdf")
# os.system("display my.pdf")
