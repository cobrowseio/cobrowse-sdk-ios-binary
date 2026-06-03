// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "CobrowseSDK",
    platforms: [
        .macOS(.v10_13), .iOS(.v15)
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
