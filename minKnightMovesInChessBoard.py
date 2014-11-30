import numpy as np
import copy
def computeNextSteps(s):
	
	r = s/8
	c = (s)%8
	
	candidates = [(r-2)*8 + c + 1, (r-2)*8 + c - 1, (r + 1)*8 + c - 2, (r - 1)*8 + c - 2, (r+2)*8 + c + 1, (r+2)* 8 +  c - 1, (r+1)*8 +  c + 2, (r-1)*8 + c + 2];
	if r == 0:
		candidates[0] = -1
		candidates[1] = -1
		candidates[3] = -1
		candidates[7] = -1
	if r == 1:
		candidates[0] = -1
		candidates[1] = -1
	if r == 7:
		candidates[2] = -1
		candidates[4] = -1
		candidates[5] = -1
		candidates[6] = -1
	if r == 6:
		candidates[4] = -1
		candidates[5] = -1
	if c == 0:
		candidates[3] = -1
		candidates[2] = -1
		candidates[1] = -1
		candidates[5] = -1
	if c == 1:
		candidates[2] = -1
		candidates[3] = -1
	if c == 7:
		candidates[0] = -1
		candidates[4] = -1
		candidates[6] = -1
		candidates[7] = -1
	if c == 6:
		candidates[6] = -1
		candidates[7] = -1

	nextSteps = [];
	for candidate in candidates:
		if candidate < 0 or candidate > 63:
			continue;
		else:
			nextSteps.append(candidate)
	return nextSteps
def findMinSteps(s, d, minPathSizeMat, pathMat, nextStepMat, pathSoFar):
	if nextStepMat[s][d] == 1:
		print "nextStepMat[s][d]==1"
		minPathSizeMat[s][d] = 1
		pathMat[s][d] = s
		return copy.deepcopy(pathSoFar)	
	
	if len(pathSoFar) + 1 >= minPathSizeMat[s][d]:
		print "Path so far going to exceed minStepSize found"
		return;
	pathsSD = [];
 	for i in range(64):
		if nextStepMat[s][i] == 1:
			print "Via Node:" + str(i)
			print "Before:PathMat[" + str(s) + "][" + str(d) + "]=" + str(pathMat[s][d])
			print "Before:minPathSizeMat[" + str(s) + "][" + str(d) + "]=" + str(minPathSizeMat[s][d]) + "-" + str(minPathSizeMat[i][d])
			
			tempPathSoFar = copy.deepcopy(pathSoFar)
			print "PathSoFar:"
			print pathSoFar
			if i not in tempPathSoFar:
				tempPathSoFar.append(i)
				if minPathSizeMat[pathSoFar[-1]][d] < len(tempPathSoFar) + 1:
					print "Path so far going to exceed minStepSize found for parent"
					continue;
				if minPathSizeMat[pathSoFar[0]][d] != 10000 and minPathSizeMat[pathSoFar[0]][d]  < len(tempPathSoFar) :
					print "Path so far going to exceed minStepSize for source node"
					continue;
				print "find all min paths from " + str(s) + "-" + str(i) + "-" + str(d)
				resPathSoFar = tempPathSoFar
				if minPathSizeMat[i][d] == 10000:	
					resPathSoFar  = findMinSteps(i, d, minPathSizeMat, pathMat, nextStepMat, tempPathSoFar)		
					print str(s) + "-" + str(i) + "-" + str(d) + "- calculated new min step size"
				else:
					print str(s) + "-" + str(i) + "-" + str(d) + "- available min step size:" + str(minPathSizeMat[i][d])
						
				if minPathSizeMat[i][d]  == 1:
					# found a path from s to d via i:
					if minPathSizeMat[i][d] + 1 < minPathSizeMat[s][d]:
						print "Found path smaller than min step size"
						pathsSD = copy.deepcopy(resPathSoFar)
						pathsSD.append(d)
						minPathSizeMat[s][d] = minPathSizeMat[i][d] + 1
						print "RePrinting:" 
						print pathsSD
						pathMat[s][d] = i
						print "PathMat[" + str(s) + "][" + str(d) + "]=" + str(pathMat[s][d])
					else:
						print "smaller path found but not smallest-" + str(s) +"-" + str(i)+"-"+str(d)
				else:
					if (minPathSizeMat[i][d] + 1) < minPathSizeMat[s][d]:
						minPathSizeMat[s][d] = minPathSizeMat[i][d] + 1
						pathMat[s][d] = i
						
						print "PathMat[" + str(s) + "][" + str(d) + "]=" + str(pathMat[s][d])
						print "minPathSizeMat[" + str(s) + "][" + str(d) + "]=" + str(minPathSizeMat[s][d]) + "-" + str(minPathSizeMat[i][d])
						
						print "2Found path smaller than min step size"
						pathsSD = copy.deepcopy(resPathSoFar)
						print "2RePrinting:" 
						print pathsSD

						
	print "returning - " + str(s) + "-" + str(d) + "-connected via -" + str(pathMat[s][d])
	print "MinPathSizeMat:" + str(minPathSizeMat[s][d])
	return pathsSD		
if __name__ == '__main__': 
	nextStepMat = [[10000 for i in range(64)] for j in range(64)]
	minPathSizeMat = [[10000 for i in range(64)] for j in range(64)]
	pathMat = [[10000 for i in range(64)] for j in range(64)]
	for i in range(64):
		nextSteps = computeNextSteps(i)
		for nextStep in nextSteps:
			nextStepMat[i][nextStep] = 1
			nextStepMat[nextStep][i] = 1
		nextStepMat[i-1][i-1] = 0
	pathsSD = findMinSteps(0, 63, pathMat, minPathSizeMat, nextStepMat, [0])
	print pathsSD
	
