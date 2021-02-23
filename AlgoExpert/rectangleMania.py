def rectangleWithBottomLeft(pointsOnRight, pointsAbove, points):
    numRect = 0
    for hor in pointsOnRight:
        for vert in pointsAbove:
            if [hor[0], vert[1]] in points:
                numRect+=1
    return numRect

def rectangleMania(points):
    numRect = 0
    for curPoint in points:
        if curPoint[1] == 0:
            # print(curPoint)
            pointsAbove = [point for point in points if point[0] == curPoint[0] and point[1] != 0]
            pointsOnRight = [point for point in points if point[1] == 0 and point[0] > curPoint[0]]
            numRect += rectangleWithBottomLeft(pointsOnRight, pointsAbove, points)
    return numRect

# O(n) space
# O(n^2) time
print("number of rectangles formed are", end = ": ")
print(rectangleMania([[0,0],[0,1],[2,0],[1,0],[1,1],[2,1]]))