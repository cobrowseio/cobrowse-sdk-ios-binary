// swift-tools-version:5.7
import PackageDescription

let package = Package(
    name: "CobrowseSDK",
    platforms: [
        .macOS(.v13), .iOS(.v15)
    ],
    products: [
        .library(
            name: "CobrowseSDK",
            targets: ["CobrowseSDK"]),
    ],
    targets: [
        .binaryTarget(
            name: "CobrowseSDK",
            path: "CobrowseSDK.xcframework"),
    ]
)
